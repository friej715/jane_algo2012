//
//  Enemy.h
//  opencvExample
//
//  Created by Jane Friedhoff on 12/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef opencvExample_Enemy_h
#define opencvExample_Enemy_h

#include "ofMain.h"

class Enemy
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    Enemy();
    virtual ~Enemy(){};
    
    
    void update();
    void draw();
    void reset();
    
    float posX;
    float posY;
    int size;
    ofColor myColor;
    float speed;
    float angle;
    
    int type;
    
    ofImage asteroid3;
    ofImage asteroid2;
    ofImage asteroid1;
    ofImage siner;
    
    bool sinMover;
    float posXOriginal;
};

#endif
