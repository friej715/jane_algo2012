//
//  food.h
//  5_rectangleXeno
//
//  Created by Jane Friedhoff on 9/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"

class food {
public:
    ofPoint loc;
    bool isFalling;
    bool isEaten;
    
    void setup(int x, int y);
    void draw();
    void update();
    
    
};