#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    letters.loadFont("arial_rounded_bold.ttf", 32);
	
	for (int i = 0; i < 100; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
        myParticle.font = &letters;
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	
	drawingStyle = 0;
	bFade = true;
    
    ofBackground(169, 45, 9);
    
    slurp.loadSound("slurp.wav");
    slurp.setMultiPlay(FALSE);
}

//--------------------------------------------------------------
void testApp::update(){

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
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	if (bFade == true) VF.fadeField(.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
    ofSetColor(169, 30, 0, 10);
    ofSetLineWidth(5);
	VF.draw();
	
	ofSetColor(225,170,90);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
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
    
    // move letters
    VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);

    
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    // attract letters
	if (button == 0) {
        VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
	} else {
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
	}
    
    for (int i = 0; i < particles.size(); i++) {
        if (ofDist(particles[i].pos.x, particles[i].pos.y, x, y) < 32) {
            particles.erase(particles.begin() + i);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
        slurp.play();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
