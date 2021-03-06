//
//  Leaf.cpp
//  emptyExample
//
//  Created by Jane Friedhoff on 9/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Leaf.h"

void Leaf::setup() {
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    
    //startTime = ofGetElapsedTimef();
    
    xVel = 1;
    yVel = 2;
    
    offsetTime = int(ofRandom(10000));
    
    c.setHsb(int(ofRandom(0, 40)), int(ofRandom(50, 100)), 150);
    
    scale = ofRandom(.5, 1);
    
    l.loadImage("leaf.png");
}

void Leaf::update() {
    float cosOfTime = cos((ofGetElapsedTimef() - offsetTime));
    float cosOfTimeMapped = ofMap(cosOfTime, -1, 1, -1.5, 1.5); // probably doesn't even need to be mapped
    
    float sinOfTime = -sin((ofGetElapsedTimef() - offsetTime));
    float sinOfTimeMapped = ofMap(sinOfTime, -1, 1, -.25, .25);
    
    //cout << cosOfTimeMapped <<endl;

    pos.x += cosOfTimeMapped;
    yVel = sinOfTimeMapped + .75;
    pos.y += yVel;
    
    
    if (pos.y > ofGetHeight()) {
        pos.y = 0;
    }
    
}


void Leaf::draw() {
    ofFill();
    ofEnableAlphaBlending();
    ofSetColor(c);
    ofPushMatrix();
    l.draw(pos.x, pos.y, l.width*scale, l.height*scale);
    
}