#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    // begin default video stuff
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
    
    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);
    
	bLearnBakground = true;
	threshold = 40;
    // end default video stuff
    
    
    scaleValue = ofGetWidth()/320; // video is taken at 320 so we need to scale it up when we draw it
    debugVideoOn = false; // just a boolean for some extra video stuff; helpful for debugging
    
    //put the player on the center bottom of the screen
	shipPosX = ofGetWidth()/2;
	shipPosY = ofGetHeight() - 150;
    
	movementSpeed = 6; //tweak this to change how fast the ship will move
    
    //create enemies
	for(int i = 0; i < 25; i++){
		Enemy myEnemy;
		enemies.push_back(myEnemy);
	}
    
    // setting up vector field (helps make smoke look more natural)
    VF.setupField(60,40,ofGetWidth(), ofGetHeight());
    VF.randomizeField(.25);
    
    shipIsSmoking = false;
    screenIsShaking = false;
    
    health = 100;
    
    gameState = 0;

    // images, sounds, fonts
    ship.loadImage("ship.png");
    background.loadImage("background_old.png");

    explode1.loadImage("Explode1.png");
    explode2.loadImage("Explode2.png");
    explode3.loadImage("Explode3.png");
    explode4.loadImage("Explode4.png");
    explode5.loadImage("Explode5.png");
    
    hitSound.loadSound("Explosion4.wav");
    hitSound.setMultiPlay(false);
    
    explosionSound.loadSound("Explosion10.wav");  
    explosionSound.setMultiPlay(true);
    
    backgroundSound.loadSound("01 Mess.mp3");
    backgroundSound.setLoop(true);
    backgroundSound.play();
    
    headerFont.loadFont("ka1.ttf", 64);
    subheaderFont.loadFont("ka1.ttf", 32);
    
    currentY = -9250; // need to push gradient off screen while having blue on screen
    
    // for explosion animation
    explodeState = 1;
    explodeShip = false;
    
    ofSetVerticalSync(TRUE);
    ofSetFrameRate(60);
    
    for (int i = 0; i < 1; i++) {
        ofPoint p;
        p.x = ofRandom(1680);
        p.y = ofRandom(1050);
        blackHolePoints.push_back(p);
    }
    
    for (int h = 0; h < blackHolePoints.size(); h++) {
        for (int i = 0; i < 30; i++) {
            particle p;
            p.setInitialCondition(blackHolePoints[h].x + ofRandom(-10, 10), blackHolePoints[h].y + ofRandom(20, 30),0,0);
            blackHoleParticles.push_back(p);
        }
    }
    
    for (int i = 0; i < 50; i++) {
        ofPoint p;
        p.x = ofRandom(ofGetWidth());
        p.y = ofRandom(ofGetHeight());
        
        starPoints.push_back(p);
        
        float f;
        
        f = ofRandom(1, 5);
        
        starDepth.push_back(f);
    }
    
    // create chaser
    Chaser myChaser;
    chasers.push_back(myChaser);
    
    // create planet
    
    for (int i = 0; i < 3; i++) {
        Planet myPlanet;
        planets.push_back(myPlanet);   
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    scrollY-=.05; // shifting noise bg down

    for (int i = 0; i < starPoints.size(); i++) {
        starPoints[i].y += ofMap(starDepth[i], 1, 5, .5, 1);
        
        if (starPoints[i].y >= ofGetHeight()) {
            starPoints[i].y = 0;
        }
    }
    
    if (gameState == 1) {
        //currentY+=3; // shifting background down
        
        // begin default video stuff
        bool bNewFrame = false;
        
        vidGrabber.grabFrame();
        bNewFrame = vidGrabber.isFrameNew();
        
        if (bNewFrame){
            
            #ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
            #else
            colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
            #endif
            
            grayImage = colorImg;
            if (bLearnBakground == true){
                grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
                bLearnBakground = false;
            }
            
            // take the abs value of the difference between background and incoming and then threshold:
            grayDiff.absDiff(grayBg, grayImage);
            grayDiff.threshold(threshold);
            grayDiff.mirror(false, true);
            
            // find contours which are between the size of 50 pixels and 1/3 the w*h pixels.
            // also, find holes is set to true so we will get interior contours as well....
            contourFinder.findContours(grayDiff, 50, (340*240)/3, 10, true);	// find holes
        }
        
        
        shipPosInFloat = ((shipPosX / ofGetWidth()) * 2) - 1; //set the position to a 0 to 2 float, then do -1 so you get a -1 to 1
        
        if (averageBlobX > -1 && averageBlobX < 1) {
            shipPosX += (averageBlobX - shipPosInFloat) * movementSpeed; //move the ship in the direction of averageBlobX. The farther averageBlobX is, the faster the ship will move in that direction.
        }
        
        //keep ship from going offscreen
        if(shipPosX < 15) { shipPosX = 15;}
        else if (shipPosX > ofGetWidth() - 15) { shipPosX = ofGetWidth() - 15; }
        
        averageBlobX = moveShipValue();
        
        //update enemies
        for(int i = 0; i < enemies.size(); i++){
            enemies[i].update();
        }
        
        //update chaser
        for(int i = 0; i < chasers.size(); i++){
            chasers[i].update(shipPosX, shipPosY);
        }
        
        //update planet
        for(int i = 0; i < planets.size(); i++){
            planets[i].update();
        }
        
        // particlessssssszzz
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            
            // get the force from the vector field: 
            ofVec2f frc;
            frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
            particles[i].addForce(frc.x, frc.y);
            particles[i].addForce(0,0.08f);
            particles[i].addDampingForce();
            particles[i].addRepulsionForce(shipPosX, shipPosY, 30, 2);
            particles[i].update();
        }
        
        for (int i = 0; i < particles.size(); i++) {
            if (particleAlphas[i]>0) {
                particleAlphas[i]-=2;
            }
        }
        
        
        shipIsHit = false;
        for (int i = 0; i < enemies.size(); i++) {
            if (ofDist(shipPosX, shipPosY, enemies[i].posX, enemies[i].posY) < 15 + (enemies[i].size/2)) {
                shipIsHit = true;
                hitSound.play();
                enemies[i].reset();
                
                screenIsShaking = true;
                
                shakeStartTime = ofGetElapsedTimeMillis();
                timeLeftToShake = 1000;
            }
        }
        
        for (int i = 0; i < chasers.size(); i++) {
            if (ofDist(shipPosX, shipPosY, chasers[i].posX, chasers[i].posY) < chasers[i].size/2) {
                hitSound.play();
                chasers[i].posX = ofRandom(ofGetWidth());
                chasers[i].posY = ofRandom(2200, 4400);
                
                shipIsHit = true;
                
                screenIsShaking = true;
                
                shakeStartTime = ofGetElapsedTimeMillis();
                timeLeftToShake = 1000;
            }
        }
        
        
        if (screenIsShaking) {
            
            screenShakeX = ofRandom(20);
            screenShakeY = ofRandom(5);
            
            if (ofGetElapsedTimeMillis() > timeLeftToShake + shakeStartTime) {
                screenIsShaking = false;
            }
        }
        
        
        if (shipIsHit)      health-=15;
        if (health < 50)    shipIsSmoking = true;
        
        if (health <= 0) {
            cout << "fire health" << endl;
            explodeShip = true;
            startTimeExplode = ofGetElapsedTimeMillis();
            intervalExplode = 200;
            health = 1; // bump it up just above so that startimeexpode doesn't keep getting set. this is janky as fuck but it's 3am
        } 
        
        if (explodeShip == true) {
            if (ofGetElapsedTimeMillis() > startTimeExplode + intervalExplode) {
                cout << "interval" << endl;
                explodeState++;
                explosionSound.play();
                startTimeExplode = ofGetElapsedTimeMillis();
            }
            
            
            if (explodeState == 6)      gameState = 2;
            
        }
        

    }
    
}

//--------------------------------------------------------------
float testApp::moveShipValue() {
    // really ramiro's code since i am terrible at physics
    
    float totalSize = 0;
    float totalX = 0;
    
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        // we map the center of each blob to between -1.2 and 1.2 (so it goes to the edge
        // then we multiply it by the size of that blob
        // and add it to totalX
        totalX += (ofMap(contourFinder.blobs[i].boundingRect.getCenter().x, 0, 320, -1.2, 1.2) * contourFinder.blobs[i].boundingRect.width);
        
        // then we add each blob's size to totalSize
        totalSize += contourFinder.blobs[i].boundingRect.width;
    }
    
    // comparing it like this helps us create a sense of weight for bigger blobs
    // and this gives us a number between -1 and 1 in the end
    return (totalX/totalSize);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    makeNoise();
    ofSetColor(255);
//    VF.draw();
    
    for (int i = 0; i < starPoints.size(); i++) {
        ofSetColor(ofMap(starDepth[i], 1, 5, 200, 255));
        ofRect(starPoints[i].x, starPoints[i].y, starDepth[i], starDepth[i]);
    }
    
    if (gameState == 0) {
        // endscreen really just means non-gameplay-screen. oops. coding at 3am~
        noiseForEndscreen+=.01; 
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
        endscreenAngle = ofMap(ofNoise(noiseForEndscreen), 0, 1, -1, 1);
        endscreenAngle*=30;
        ofRotateZ(endscreenAngle);
        
        ofTranslate(ofRandom(3), ofRandom(3));
        ofFill();
        ofColor c;
        c.setHsb(ofRandom(30), 255, 150);
        ofSetColor(c);
        headerFont.drawString("TEAM SPACE",  -headerFont.stringWidth("TEAM SPACE")/2, 0); 
        
        ofPopMatrix();
        
        subheaderFont.drawString("SPACE TO START",  ofGetWidth()/2-subheaderFont.stringWidth("SPACE TO START")/2, ofGetHeight()/2 + 300);
    }
    
    
    if (gameState == 1) {
        
        ofEnableAlphaBlending();
        ofSetColor(100, 100, 100, 20);
        grayDiff.draw(0, 0, ofGetWidth(), ofGetHeight());
        ofDisableAlphaBlending();
        
        // in case you want to see the guts of what's going on, you can turn this on with 'd'
        if (debugVideoOn) {
            ofSetHexColor(0xffffff);
            colorImg.draw(20,20);
            grayImage.draw(360,20);
            grayBg.draw(20,280);
            grayDiff.draw(360,280);
            
            // finally, a report:
            ofSetHexColor(0xffffff);
            char reportStr[1024];
            sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i, fps: %f", threshold, contourFinder.nBlobs, ofGetFrameRate());
            ofDrawBitmapString(reportStr, 20, 600);
            
            // because the video is taken at 320x240, we need to scale it up when we view it/draw it
            ofPushMatrix();
            ofScale(scaleValue, scaleValue);
            ofSetHexColor(0xffffff);
            for (int i = 0; i < contourFinder.nBlobs; i++){
                contourFinder.blobs[i].draw(0,0); // let's draw each blob individually
            }
            ofPopMatrix();
        }
        // end guts
        
        
        // let's shake the screen
        if (screenIsShaking) {
            ofPushMatrix();
            ofTranslate(screenShakeX, screenShakeY);
        }
        
        // planets
        for (int i = 0; i < planets.size(); i++) {
            planets[i].draw();
        }
    
        // fire
        ofPushMatrix();
        ofTranslate(shipPosX, shipPosY);
        ofRotateY(CLAMP(ofMap(shipPosInFloat-averageBlobX, -1, 1, 35, -35), -35, 35));
        for (int x = - 10; x < 8; x+=4) {
            for (int y = ship.height - 10; y < shipPosY + 30; y+=7) {
                ofColor c;
                c.setHsb(ofRandom(60), 255, 255);
                ofFill();
                
                ofEnableAlphaBlending();
                ofSetColor(c, ofMap(y, ship.height - 10, ship.height + 30, 255, 2));
                ofRect(x, y, 5, 7);
                ofDisableAlphaBlending();
            }
        }
        ofPopMatrix();

        ofSetColor(255);
        ofEnableAlphaBlending();
        if (explodeShip == false) {
            // draw ship
            ofPushMatrix();
            ofTranslate(shipPosX, shipPosY);
            ofRotateY(CLAMP(ofMap(shipPosInFloat-averageBlobX, -1, 1, 35, -35), -35, 35));
            ship.draw(-ship.width/2, 0);
            ofPopMatrix();
            
            //ship.draw(shipPosX - ship.width/2, shipPosY);
        } else {
            if (explodeState == 1)      explode1.draw(shipPosX - explode1.width/2, shipPosY - explode1.height/2);
            if (explodeState == 2)      explode2.draw(shipPosX - explode2.width/2, shipPosY - explode2.height/2);
            if (explodeState == 3)      explode3.draw(shipPosX - explode3.width/2, shipPosY - explode3.height/2);
            if (explodeState == 4)      explode4.draw(shipPosX - explode4.width/2, shipPosY - explode4.height/2);
            if (explodeState == 5)      explode5.draw(shipPosX - explode5.width/2, shipPosY - explode5.height/2);
        }
        ofDisableAlphaBlending();
        
        // creating smoke
        if (shipIsSmoking) {
            for (int i = 0; i < ofMap(health, 0, 55, 5, 1); i++){
                particle myParticle;
                myParticle.setInitialCondition(shipPosX + ofRandom(-10, 10), shipPosY + 20 + ofRandom(20, 30),0,0);
                particles.push_back(myParticle);
                
                float f;
                f = ofMap(health, 0, 55, 150, 20);
                particleAlphas.push_back(f);
            }
        }
        
        //draw average blob position (debug only)
        //	ofSetColor(0, 255, 0);
        //	ofEllipse(ofMap(averageBlobX, -1, 1, 0, ofGetWidth()), ofGetHeight() - 20, 20, 20);
        
        //draw enemies
        for(int i = 0; i < enemies.size(); i++){
            enemies[i].draw();
        }
        
        // draw chasers
        for (int i = 0; i < chasers.size(); i++) {
            chasers[i].draw();
        }
        
        
        // particlessssss
        for (int i = 0; i < particles.size(); i++){
            ofEnableAlphaBlending();
            ofSetColor(ofMap(health, -15, 50, 0, 100), particleAlphas[i]);
            ofFill();
            particles[i].draw();
            ofDisableAlphaBlending();
        }
        
        if (screenIsShaking) {
            ofPopMatrix();
        }
        
    }
    
    if (gameState == 2) {
        noiseForEndscreen+=.01;
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
        endscreenAngle = ofMap(ofNoise(noiseForEndscreen), 0, 1, -1, 1);
        endscreenAngle*=30;
        ofRotateZ(endscreenAngle);
        
        ofTranslate(ofRandom(3), ofRandom(3));
        ofFill();
        ofColor c;
        c.setHsb(ofRandom(30), 255, 150);
        ofSetColor(c);
        headerFont.drawString("YOU DIED\nIN SPACE",  -headerFont.stringWidth("YOU DIED\nIN SPACE")/2, 0); 
        
        ofPopMatrix();
        
    }

}
//--------------------------------------------------------------
void testApp::makeNoise() {
    int boxW = 342;
    int boxH = 256;
    
    int cellSize = 4;
    
    float noiseZoom=0.01;
    
    ofPushMatrix();
    ofScale(6, 6);
    for (int x = 0; x < boxW; x+=cellSize) {
        for (int y = 0; y < boxH; y+=cellSize) {
            int val;
            
            val = ofNoise(scrollX+x * noiseZoom, scrollY+y * noiseZoom) * 30;
            
            ofSetColor(val);
            ofFill();
            ofRect(x, y, cellSize, cellSize);
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	switch (key){
		case 'b':
			bLearnBakground = true;
			break;
		case '=':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
        case 'd':
            // shows extra video stuff; probs not necessary but good to have
            debugVideoOn = !debugVideoOn;
            break;
        case 's':
            shipIsSmoking = !shipIsSmoking;
            break;
        case 'w':
            screenIsShaking = !screenIsShaking;
            break;
        case ' ':
            if (gameState == 0)     gameState = 1;
            break;
            
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    //averageBlobX = ofMap(x, 0, 1680, -1, 1);
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
