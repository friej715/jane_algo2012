//
//  Leaf.h
//  emptyExample
//
//  Created by Jane Friedhoff on 9/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Leaf {
public:
    ofPoint pos;
    ofColor c;
    
    float xVel;
    float yVel;
    
    int offsetTime;
    
    void setup();
    void update();
    void draw();
    
    float scale;
    
};
