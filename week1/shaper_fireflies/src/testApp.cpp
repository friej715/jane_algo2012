#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bg.loadImage("bg2.jpg");
    sounds.loadSound("sound.mp3");
    
    for (int i = 0; i < 50; i++) {
        Firefly f;
        f.setup();
        fireflies.push_back(f);
    }
    
    ofSetVerticalSync(TRUE);
    ofSetRectMode(OF_RECTMODE_CENTER);
    pct = 0;
    
    interval = 5000;
    startTime = ofGetElapsedTimeMillis();
    
    sounds.setLoop(TRUE);
    sounds.play();
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < fireflies.size(); i++) {
        fireflies[i].update();
        fireflies[i].interpolateByPct(pct);
    }
    
    pct += 0.001f;
    
    cout << pct << endl;
    
    if (ofGetElapsedTimeMillis() - startTime > interval) {
        for (int i = 0; i < fireflies.size(); i++) {
            fireflies[i].changeDir();
        }
        pct = 0;
        startTime = ofGetElapsedTimeMillis();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    bg.draw(0, 0);
    for (int i = 0; i < fireflies.size(); i++) {
        fireflies[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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