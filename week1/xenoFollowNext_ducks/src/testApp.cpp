#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	for (int i = 0; i < 5; i++) {
        rectangle f;
        ducks.push_back(f);
    }
}

//--------------------------------------------------------------
void testApp::update(){

    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            ducks[i].xenoToPoint(mouseX, mouseY);
        } else {
            ducks[i].xenoToPoint(ducks[i-1].pos.x, ducks[i-1].pos.y);   
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < 5; i++) {
        ducks[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){

}
