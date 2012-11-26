#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(31, 129, 129);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	
	particle myParticle;
	myParticle.setInitialCondition(400,400,0,0);//0
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(500,400,0,0);//1
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(400,500,0,0);//2
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(500,500,0,0);//3
	particles.push_back(myParticle);
    
	myParticle.setInitialCondition(600,500,0,0);//4
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(500,600,0,0);//5
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(600,600,0,0);//6
	particles.push_back(myParticle);

	
	spring mySpring;
		
//	for (int i = 0; i < particles.size(); i++){
//		
//		mySpring.distance		= 100;
//		mySpring.springiness	= 0.2f;
//		mySpring.particleA = & (particles[i  ]);
//		mySpring.particleB = & (particles[(i+1) % particles.size()]);
//		springs.push_back(mySpring);
//	}

    mySpring.distance		= (particles[0].pos-particles[1].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[1]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[1].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);  
    
    mySpring.distance		= (particles[2].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[3].pos-particles[4].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (particles[4]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[4].pos-particles[5].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[4]);
	mySpring.particleB = & (particles[5]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[5].pos-particles[6].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[5]);
	mySpring.particleB = & (particles[6]);
	springs.push_back(mySpring);
    
    //-------------------
    
    mySpring.distance		= (particles[0].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[3].pos-particles[6].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (particles[6]);
	springs.push_back(mySpring);
    
    
    
    
    //-------------------
	mySpring.distance		= (particles[0].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);

	
    mySpring.distance		= (particles[3].pos-particles[5].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (particles[5]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[4].pos-particles[6].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[4]);
	mySpring.particleB = & (particles[6]);
	springs.push_back(mySpring);

    mySpring.distance		= (particles[2].pos-particles[5].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[5]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[1].pos-particles[4].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[4]);
	springs.push_back(mySpring);

		
	
}

//--------------------------------------------------------------
void testApp::update(){
    
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
    
	springs[12].distance = 100 + 50 * sin(ofGetElapsedTimef()*8);
	springs[13].distance = 100 + 50 * sin(ofGetElapsedTimef()*8 + PI);
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		//particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
    
    particles[3].addAttractionForce(mouseX, mouseY, 800, 3);
    particles[0].addRepulsionForce(mouseX, ofGetHeight(), 800, 2);
    particles[6].addRepulsionForce(mouseX, ofGetHeight(), 800, 2);
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	

	ofSetColor(0xffffff);
	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].draw();
//	}
//	
//	for (int i = 0; i < springs.size(); i++){
//		springs[i].draw();
//	}
    
    
    ofSetColor(115, 2, 64);
    ofBeginShape();
    ofVertex(particles[0].pos.x, particles[0].pos.y);
    ofVertex(particles[2].pos.x, particles[2].pos.y);
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofVertex(particles[1].pos.x, particles[1].pos.y);
    ofEndShape();
    
    ofSetColor(115, 2, 64);
    ofBeginShape();
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofVertex(particles[5].pos.x, particles[5].pos.y);
    ofVertex(particles[6].pos.x, particles[6].pos.y);
    ofVertex(particles[4].pos.x, particles[4].pos.y);
    ofEndShape();
    
    ofSetColor(242, 188, 121);
    ofBeginShape();
    ofVertex(particles[0].pos.x, particles[0].pos.y);
    ofVertex(particles[1].pos.x, particles[1].pos.y);
    ofVertex(particles[2].pos.x, particles[2].pos.y);
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofEndShape();
    
    ofSetColor(242, 188, 121);
    ofBeginShape();
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofVertex(particles[4].pos.x, particles[4].pos.y);
    ofVertex(particles[5].pos.x, particles[5].pos.y);
    ofVertex(particles[6].pos.x, particles[6].pos.y);
    ofEndShape();
    
    
    ofSetColor(0);
    ofCircle(particles[3].pos.x, particles[3].pos.y, 20);

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
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
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

