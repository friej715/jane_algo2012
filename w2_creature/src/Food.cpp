//
//  Food.cpp
//  5_rectangleXeno
//
//  Created by Jane Friedhoff on 9/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Food.h"

void Food::setup() {
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
}

void Food::update() {
    
    
}

void Food::draw() {
    ofSetColor(255);
    ofRect(pos.x, pos.y, 10, 10);
}