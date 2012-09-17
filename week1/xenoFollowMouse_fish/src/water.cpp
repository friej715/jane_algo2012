//
//  water.cpp
//  5_rectangleXeno
//
//  Created by Jane Friedhoff on 9/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "water.h"

void water::setup(int x, int y) {
    loc.x = x;
    loc.y = y;
    
    c.set(50, 50, 200);
    
    noiseNum = ofRandom(0,1);
}



void water::update() {
    noiseNum+=.0005;
    c.b += 100+ofNoise(noiseNum)*2;
    cout<<c.b << endl;
    
}


void water::draw() {
    ofSetColor(c);
    ofEllipse(loc.x, loc.y, 200, 200);
    
}