#include "testApp.h"
//---------
/*
 to-do:
    - change color of particles dep. on distance from original point
    - change color of lines/size of lines dep on distance from original point (??)
    - offset forces so they're not growing/shrinking at the same time
 
 
*/

//--------------------------------------------------------------
void testApp::setup(){	
    
    ofBackground(255, 252, 191);
    
    for (int i = 0; i < 4; i++) {
        ofColor c;
        colors.push_back(c);
    }
    
    colors[0].set(43, 16, 59);
    colors[1].set(32, 57, 84);
    colors[2].set(112, 153, 75);
    colors[3].set(200, 204, 108);
    
	
	ofSetVerticalSync(true);
	//ofSetFrameRate(60);
	
    for (int i = 0; i < 10; i++) {
        ofPoint p;
        p.x = ofRandom(ofGetWidth());
        p.y = ofRandom(ofGetHeight());
        
        snowflakePositions.push_back(p);
        
        cout << "p: " << p.x << endl;
    }
	
    
    particleImage.loadImage("particle1.png");
    
	for (int i = 0; i < 500; i++){
		particle myParticle;
        int snowflakeNum = int(ofRandom(snowflakePositions.size()));
        myParticle.originalPoint = snowflakePositions[snowflakeNum];
        
		myParticle.setInitialCondition(snowflakePositions[snowflakeNum].x + ofRandom(-10,10),snowflakePositions[snowflakeNum].y+ofRandom(-10,10),0,0);

        //myParticle.setInitialCondition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, 0);
        
        myParticle.image = &particleImage;
        
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;

    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //VF.clear();
    
//    if (sin(ofGetElapsedTimef())<=-.9) {
//        for (int i = 0; i < 5; i++) {
//            VF.addClockwiseCircle(ofRandom(ofGetWidth()/2), ofRandom(ofGetHeight()/2), 50, sin(ofGetElapsedTimef()));
//        }
//    }
    
    for (int i = 1; i < snowflakePositions.size(); i++) {
        VF.addClockwiseCircle(snowflakePositions[i].x, snowflakePositions[i].y,200, (sin(ofGetElapsedTimef()*10)+3*i)*0.01);   
    }

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		//particles[i].addDampingForce();
		particles[i].update();
        //particles[i].bounceOffWalls();
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
//	ofSetColor(0,130,130, 200);
	VF.draw();
	
	ofSetColor(0,0,0);
	
	for (int i = 0; i < particles.size(); i++){
        float currentDist;
        currentDist = ofDist(particles[i].pos.x, particles[i].pos.y, particles[i].originalPoint.x, particles[i].originalPoint.x);
        
        int mappedDist;
        mappedDist = int(ofMap(currentDist, 0, 500, 0, 3));
        
        if (mappedDist == 0)    particles[i].c.set(colors[0]);
        if (mappedDist == 1)    particles[i].c.set(colors[1]);
        if (mappedDist == 2)    particles[i].c.set(colors[2]);
        if (mappedDist == 3)    particles[i].c.set(colors[3]);
        
		particles[i].draw();
	}
	
	ofSetColor(0,130,130, 200);
	ofRect(30,30,300,75);
	ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
	
	
	ofSetColor(255,255,130);
	switch (drawingStyle){
		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
			break;
		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
			break;
		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
			break;
		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
			break;
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//	if (button == 0) {
//		switch (drawingStyle){
//			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
//				break;
//			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
//				break;
//			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
//				break;
//			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
//				break;
//		}		
//	} else {
//		
//		particles.erase(particles.begin());
//		particle myParticle;
//		myParticle.setInitialCondition(x,y,0,0);
//		particles.push_back(myParticle);
//		
//		
//	}
    
//    VF.addClockwiseCircle(x, y, 50, sin(ofGetElapsedTimef()));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    VF.addClockwiseCircle(x, y, 50, sin(ofGetElapsedTimef()));
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
