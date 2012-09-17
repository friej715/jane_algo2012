//
//  food.cpp
//  5_rectangleXeno
//
//  Created by Jane Friedhoff on 9/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "food.h"


//------------------------------------------------------------------
void food::setup(int x, int y) {
    loc.x = x;
    loc.y = y;
    
    isFalling = true;
    isEaten = false;
}

//------------------------------------------------------------------
void food::update() {
    if (loc.y + 20 <= ofGetHeight()) { // change magic numbers later
        isFalling = true;
    } else {
        isFalling = false;
    }
    
    if (isFalling) {
        loc.y+=2;
    }
    
}

//------------------------------------------------------------------
void food::draw() {
    ofSetColor(255);
    ofRect(loc.x, loc.y, 10, 10);
}
