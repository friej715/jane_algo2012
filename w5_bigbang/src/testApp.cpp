#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
	VF.randomizeField(1.5);	
    
    for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
//	VF.fadeField(0.99f);
    	VF.randomizeField(1.5);
    
    for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
        
        particles[i].addAttractionForce(ofGetWidth()/2, ofGetHeight()/2, 500, sin(ofGetElapsedTimef()));
		particles[i].addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, 500, cos(ofGetElapsedTimef()));
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
//	ofSetColor(0,130,130, 200);
//	VF.draw();
//	ofDisableAlphaBlending();
    
    ofEnableAlphaBlending();
    ofSetColor(250, 250, 250, 200);
    for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    ofDisableAlphaBlending();
		
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
	if (button == 0){
		VF.addOutwardCircle(x,y, 100, 0.3) ;
	} else {
		VF.addCounterClockwiseCircle(x, y, 200, 0.3);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
