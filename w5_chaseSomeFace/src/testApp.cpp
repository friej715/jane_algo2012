#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);   
    //video  
    videoWidth = 320;  
    videoHeight = 240;  
    scrnRatio = 3.2;  
    sizeRatio = 1.28;  
    vidGrabber.setVerbose(true);  
    vidGrabber.initGrabber(videoWidth, videoHeight);  
    colorImg.allocate(videoWidth, videoHeight);  
    grayImage.allocate(videoWidth, videoHeight); 
    
    // load the correct xml file from the bin/data/haarXML/ folder  
    finder.setup("haarcascade_frontalface_default.xml");  
    // haarFinder.setup("haarXML/haarcascade_lefteye_2splits.xml");  
    // haarFinder.setup("haarXML/haarcascade_eye.xml");  
    //haarFinder.setup("haarXML/haarcascade_profileface.xml"); 
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
	VF.randomizeField(1.5);	
    
    for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(300,ofGetWidth()-300),ofRandom(300,ofGetHeight()-300),0,0);
		particles.push_back(myParticle);
	}
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //video  
    bool bNewFrame = false;  
    vidGrabber.grabFrame();  
    bNewFrame = vidGrabber.isFrameNew();  
    if (bNewFrame){  
        colorImg.setFromPixels(vidGrabber.getPixels(), videoWidth, videoHeight);  
        grayImage = colorImg;
        grayImage.mirror(false, true);
        finder.findHaarObjects(grayImage);  
    } 
    
    VF.randomizeField(2);
    
    if (finder.blobs.size() > 0) {
        //            VF.addOutwardCircle(finder.blobs[0].boundingRect.x + (finder.blobs[0].boundingRect.width/2), finder.blobs[0].boundingRect.y, 100, 5);
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            
            particles[i].addAttractionForce(finder.blobs[0].boundingRect.x + (finder.blobs[0].boundingRect.width/2), finder.blobs[0].boundingRect.y + (finder.blobs[0].boundingRect.height/2), 500, 10);
            particles[i].addRepulsionForce(finder.blobs[0].boundingRect.x + (finder.blobs[0].boundingRect.width/2), finder.blobs[0].boundingRect.y + (finder.blobs[0].boundingRect.height/2), 500, 7);
            particles[i].addClockwiseForce(finder.blobs[0].boundingRect.x + (finder.blobs[0].boundingRect.width/2), finder.blobs[0].boundingRect.y + (finder.blobs[0].boundingRect.height/2), 10, 10);
            // get the force from the vector field: 
            ofVec2f frc;
            frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
            particles[i].addForce(frc.x, frc.y);
            particles[i].addDampingForce();
            particles[i].update();
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    colorImg.mirror(false, true);
    colorImg.draw(0, 0, 1024, 768);
	ofNoFill();
    
    pixels = colorImg.getPixels();
	int w = colorImg.width;
	int h = colorImg.height;
    
    ofPushMatrix();
    ofScale(scrnRatio, scrnRatio);
    if (finder.blobs.size() > 0) {
//        for(int i = 0; i < finder.blobs.size(); i++) {
//            ofRectangle cur = finder.blobs[i].boundingRect;
//            ofRect(cur.x, cur.y, cur.width, cur.height);
//        }
        
        for (int i = 0; i < particles.size(); i++) {
            int index = (particles[i].pos.y * 320 + particles[i].pos.x) * 3;
            ofColor color;
            color.r = pixels[index]; //red pixel
            color.g = pixels[index+1] ; //blue pixel
            color.b = pixels[index+2] ; //green pixel
            ofSetColor(color, 100);
            ofFill();
            particles[i].draw();
        }
    }
    ofPopMatrix();
    
    ofSetColor(255);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
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