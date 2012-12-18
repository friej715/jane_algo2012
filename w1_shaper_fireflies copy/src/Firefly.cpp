//
//  Firefly.cpp
//  emptyExample
//
//  Created by Jane Friedhoff on 9/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Firefly.h"

void Firefly::setup() {
//    pos.x = ofRandom(ofGetWidth());
//    pos.y = ofRandom(ofGetHeight());

    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    w = 10;
    h = 10;
    
    angle = ofRandom(2*PI);
    
    expanse = 5;
    
    shaper = 1;
    
    followPoint.x = ofRandom(ofGetWidth());
    followPoint.y = ofRandom(ofGetHeight());
    
    alpha = 5;
    followAlpha = 75;
    
    interval = int(ofRandom(1000, 5000));
    startTime = ofGetElapsedTimeMillis();
    
}

void Firefly::update() {
    
    pct += 0.001f;
    
    if (isMovingClockwise){
        angle+=.05;
    } else {
        angle-=.05;
    }
    
    
    pos.x += expanse*cos(angle);
    pos.y += expanse*sin(angle);
    
    previousPoints.push_back(pos);
    
    if (previousPoints.size() > 70) {
        previousPoints.erase(previousPoints.begin());
    }
    
}

void Firefly::draw() {
    
    ofSetColor(col, alpha);
    ofFill();
    ofEnableAlphaBlending();
    for (int i = 0; i < 5; i++) {
        ofEllipse(pos.x += 7*cos(angle+i*5), pos.y += 7*sin(angle+i*5), w*4, h*4);
    }
    
    
    for (int i = 0; i < previousPoints.size(); i++) {
        ofCircle(previousPoints[i].x, previousPoints[i].y, i);
    }
    
//    ofSetColor(255, 200);
//    ofFill();
//    ofEllipse(pos.x, pos.y, w, h);

}

void Firefly::changeDir() {
    followPoint.x = ofRandom(ofGetWidth());
    followPoint.y = ofRandom(ofGetHeight());
    

}


//------------------------------------------------------------------
void Firefly::interpolateByPct(float myPct){
	
	// powf (2, 3) = 8
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * pos.x + (pct) * followPoint.x;
	pos.y = (1-pct) * pos.y + (pct) * followPoint.y;
    
    alpha = (1-pct) * alpha + (pct) * followAlpha;
    
}