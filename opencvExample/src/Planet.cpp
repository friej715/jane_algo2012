#include "Planet.h"
#include "ofMain.h"

//------------------------------------------------------------
Planet::Planet(){
	posX = ofRandom(30, ofGetWidth() - 30);
	posXOriginal = posX;
	posY = ofRandom(-100, 500); //change this to -2000, -1000
	size = 25;
	moonSize = 5;
	myColor = ofColor(ofRandom(1, 100), ofRandom(1, 100), ofRandom(0, 100));
	speedY = ofRandom(.1, .3);
	speedX = ofRandom(-.1, .1);
    image.loadImage("Planet.png");
}

void Planet::update(){
	posX += speedX;
	posY += speedY;
	

	//if the enemy goes off screen, move them back to the top
	if(posY > ofGetHeight() + 100) { 
		posX = ofRandom(30, ofGetWidth() - 30);
		posY = ofRandom(-400, -100); 
	}

	moonX = posX + 70 * sin(posY / 50);
	moonY = posY + 50 * cos(posY / 50);

}

void Planet::draw(){
	//draw enemy
    ofEnableAlphaBlending();
	
    ofSetColor(myColor);
	image.draw(posX, posY, size);
    
    ofSetColor(100, 100, 100);
	ofCircle(moonX, moonY, moonSize);
    
    ofDisableAlphaBlending();
}