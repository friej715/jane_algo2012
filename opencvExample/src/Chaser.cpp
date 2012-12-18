#include "Chaser.h"
#include "ofMain.h"

//------------------------------------------------------------
Chaser::Chaser(){
	posX = ofRandom(30, ofGetWidth() - 30);
	posY = ofRandom(-1000, -100);
	size = 33;
	tail2Size = size - 5;
	tail3Size = tail2Size - 5;
	tail4Size = tail3Size - 5;
	pos2X = posX;
	pos3X = posX;
	pos4X = posX;
	pos2Y = posY - size;
	pos3Y = pos2Y - tail2Size;
	pos4Y = pos3Y - tail3Size;
	myColor = ofColor(ofRandom(100, 250), ofRandom(100, 250), ofRandom(100, 250));
	speed = ofRandom(.5, 2);
	catchUpSpeed = 0.01F;
	tailCatchUpSpeed = 0.1F;
	totalHeight = 5;
}

void Chaser::update(int shipX, int shipY){
	posY += speed;
	pos2Y += speed;
	pos3Y += speed;
	pos4Y += speed;

	//if the enemy goes off screen, move them back to the top
	if(posY > ofGetHeight() + 100) { 
		posX = ofRandom(30, ofGetWidth() - 30);
		posY = ofRandom(-400, -100); 
		pos2X = posX;
		pos3X = posX;
		pos4X = posX;
		pos2Y = posY - size;
		pos3Y = pos2Y - tail2Size;
		pos4Y = pos3Y - tail3Size;
	}

	//move in X so that it feels like a creature
	posX = catchUpSpeed * shipX + (1-catchUpSpeed) * posX; 
	pos2X = tailCatchUpSpeed * posX + (1-tailCatchUpSpeed) * pos2X; 
	pos3X = tailCatchUpSpeed * pos2X + (1-tailCatchUpSpeed) * pos3X; 
	pos4X = tailCatchUpSpeed * pos3X + (1-tailCatchUpSpeed) * pos4X;

	//eye location
	float deltaX = posX - shipX;
	float deltaY = posY - shipY;
	eyeAngle = atan2(deltaX, deltaY);

	//makes eyes blink at a random rate
	if(blinking){
		if(blinkClosing){
			eyeHeightPre--;
			if(eyeHeightPre > -1){
				eyeHeight = eyeHeightPre;
			}
			else{
				eyeHeight = 0;
			}
			if(eyeHeightPre < -5){
				blinkClosing = false;
			}
		}
		else{ //if blinking but blinkClosing is false
			eyeHeight++;
			if(eyeHeight > totalHeight){
				eyeHeight = totalHeight;
				eyeHeightPre = totalHeight;
				blinkClosing = true;
				blinking = false;
				blinkTimer = (int)ofRandom(90, 140);
			}
		}
	}
	else{ //if not blinking
		blinkTimer--;
		if(blinkTimer < 1){
			blinking = true;
		}
	}

}

void Chaser::draw(){
	//draw enemy
	ofSetColor(myColor);

	//draw head
	ofEllipse(posX, posY, size, size);

	//draw tail
	ofEllipse(pos2X, pos2Y, tail2Size, tail2Size);
	ofEllipse(pos3X, pos3Y, tail3Size, tail3Size);
	ofEllipse(pos4X, pos4Y, tail4Size, tail4Size);

	//draw eyes
	ofSetColor(255, 0, 0);

	float leftEyeX = posX - 5 * sin(eyeAngle) - 5;
	float rightEyeX = posX - 5 * sin(eyeAngle) + 5;
	float leftEyeY = posY - 7 * cos(eyeAngle) - .5 * abs(leftEyeX - posX);
	float rightEyeY = posY - 7 * cos(eyeAngle) - .5 * abs(rightEyeX - posX);

	ofEllipse(leftEyeX, leftEyeY, 5, eyeHeight);
	ofEllipse(rightEyeX, rightEyeY, 5, eyeHeight);
}