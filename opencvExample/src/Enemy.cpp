//
//  Enemy.cpp
//  opencvExample
//
//  Created by Jane Friedhoff on 12/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Enemy.h"
#include "ofMain.h"

//------------------------------------------------------------
Enemy::Enemy(){
    
    reset();
    
    
    asteroid3.loadImage("Asteroid3.png");
    asteroid2.loadImage("Asteroid2.png");
    asteroid1.loadImage("Asteroid1.png");
    siner.loadImage("Siner.png");
    
//    asteroid2.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
//    asteroid3.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
//    asteroid1.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
//    
//    
//    unsigned char * as1pixels = asteroid1.getPixels();
//    for (int i = 0; i < asteroid1.getWidth()* asteroid1.getHeight(); i++){
//        cout << as1pixels[ i * 4 + 3 ] << endl;
//        if (as1pixels[ i * 4 + 3 ] == 0){
//            as1pixels[ i * 4 + 0 ] == 0;
//            as1pixels[ i * 4 + 1 ] == 0;
//            as1pixels[ i * 4 + 2 ] == 0;
//        }
//    }
//    asteroid1.update();
//    
    
    
    
    
    
    angle = int(ofRandom(360));
    asteroid3.rotate90(angle);
    asteroid2.rotate90(angle);
    asteroid1.rotate90(angle);
    
}

void Enemy::update(){
	posY += speed;
    angle+=.25;
    
	//if the enemy goes off screen, move them back to the top
	if(posY > ofGetHeight() + 100) { 
		reset();
	}
    
    if (sinMover)   posX = posXOriginal + 150*sin(posY/100);
}

void Enemy::draw(){
	//draw enemy
    ofEnableAlphaBlending();
    ofNoFill();

    ofPushMatrix();
    ofTranslate(posX, posY);
    if (type == 4)          siner.draw(-siner.width/2, siner.height/2);
    
    if (type != 4) {
        ofRotate(angle);
    }
    
    if (type == 3)          asteroid3.draw(-asteroid3.width/2, -asteroid3.height/2);
    if (type == 2)          asteroid2.draw(-asteroid2.width/2, -asteroid2.height/2);
    if (type == 1)          asteroid1.draw(-asteroid1.width/2, -asteroid1.height/2);
    ofPopMatrix();
    
    ofDisableAlphaBlending();
}

void Enemy::reset() {
    
    posX = ofRandom(30, ofGetWidth() - 30);
	posY = ofRandom(-1000, -100);
    
    posXOriginal = posX;
    
    int r = int(ofRandom(100));
    cout << r << endl;
    
    if (r <= 1) {
        type = 4;
    } else if (r > 1 && r <=10) {
        type = 3;
    } else if (r > 10 && r <= 15) {
        type = 2;
    } else {
        type = 1;
    }
    
    if (type == 3)  size = asteroid3.width;
    if (type == 2)  size = asteroid2.width;
    if (type == 1)  size = asteroid1.width;
    if (type == 4)  size = siner.width;
    
    if (type == 4) {
        sinMover = true;
    } else {
        sinMover = false;
    }
    
	speed = ofRandom(3, 5);
}