//
//  Particle.cpp
//  emptyExample
//
//  Created by Jane Friedhoff on 10/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Particle.h"

//------------------------------------------------------------
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
    damping = 0.01f;
}

//------------------------------------------------------------
void Particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void Particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void Particle::addDampingForce() {
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}


//------------------------------------------------------------
void Particle::update() {
    vel = vel + frc;
    pos = pos + vel;
    brightness-=ofRandom(.001, .2);
}

void Particle::draw() {
    ofEnableAlphaBlending();
    c.setBrightness(brightness);
    ofSetColor(c, 150);
    ofFill();
    ofCircle(pos.x, pos.y, 5);
}