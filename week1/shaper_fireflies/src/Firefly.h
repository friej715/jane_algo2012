//
//  Firefly.h
//  emptyExample
//
//  Created by Jane Friedhoff on 9/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_Firefly_h
#define emptyExample_Firefly_h
#include "ofMain.h"

class Firefly {
public:
    ofPoint pos;
    ofColor col;
    int w;
    int h;
    
    int expanse;
    
    float angle;
    bool isMovingClockwise;
    bool isSpeedingUp;
    
    ofPoint followPoint;
    float pct;
    float shaper;
    
    
    
    void setup();
    void update();
    void draw();
    void changeDir();
    void interpolateByPct(float myPct);
    

    
};








#endif
