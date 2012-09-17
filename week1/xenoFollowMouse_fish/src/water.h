//
//  water.h
//  5_rectangleXeno
//
//  Created by Jane Friedhoff on 9/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef __rectangleXeno_water_h
#define __rectangleXeno_water_h
#include "ofMain.h"

class water {
public:
    ofPoint loc;
    ofColor c;
    
    float noiseNum;
    
    void setup(int x, int y);
    void update();
    void draw();
    
};



#endif
