#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
    rectangle();
	
    void	draw(int i);
    void	xenoToPoint(float catchX, float catchY);
    void    breathe(float i);
	
    ofPoint		pos;
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    ofPoint		prevPos;
    
    bool isGoingLeft;
    
    
    float radius;
    float angle;
    
    ofPoint p1;
    ofPoint p2;
    
    int whichOne; // super-stupid way of doing this... sry d00dz
    
    ofColor c;
    
    
};

#endif // RECTANGLE_H
