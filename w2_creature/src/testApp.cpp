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
        creatureParts.push_back(f);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < 5; i++) {
        
        if (i == 0) {
            if (foods.size() > 0) {
                creatureParts[i].xenoToPoint(foods[0].pos.x, foods[0].pos.y);
            } else {
                creatureParts[i].xenoToPoint(ofGetMouseX(),ofGetMouseY());
            }
        } else {         
            creatureParts[i].xenoToPoint(creatureParts[i-1].pos.x, creatureParts[i-1].pos.y);  
        }
        
        creatureParts[i].breathe(i);
    }
    
    for (int i = 0; i < foods.size(); i++) {
        foods[i].update();
        
        if (ofDist(foods[i].pos.x, foods[i].pos.y, creatureParts[4].pos.x, creatureParts[4].pos.y) < 15) {
            foods.erase(foods.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 4; i > 0; i--) {
        ofSetColor(creatureParts[i].c);
        ofSetLineWidth(creatureParts[i].radius);
        ofLine(creatureParts[i].pos.x, creatureParts[i].pos.y, creatureParts[i-1].pos.x, creatureParts[i-1].pos.y);
    }
    
    for (int i = 5; i >=0; i--) {
        creatureParts[i].draw(i);
    }
    
    for (int i = 0; i < foods.size(); i++) {
        foods[i].draw();
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
    Food f;
    f.setup();
    foods.push_back(f);
}
