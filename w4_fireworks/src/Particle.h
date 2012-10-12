//
//  Particle.h
//  emptyExample
//
//  Created by Jane Friedhoff on 10/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_Particle_h
#define emptyExample_Particle_h
#include "ofMain.h"

class Particle {
public:
    ofPoint pos;
    ofPoint vel;
    ofPoint frc; // acceleration, basically
    
    ofColor c;
    
    float width;
    float height;
    
    float angle;
    
    float damping;
    
    int brightness;
    
    
    
    void setInitialCondition(float px, float py, float vx, float vy);
    void addForce(float x, float y);
    void addDampingForce();
    void resetForce();
    void update();
    void draw();
    
    
};

#endif
