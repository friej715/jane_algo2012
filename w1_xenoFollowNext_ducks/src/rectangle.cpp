#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
    
	catchUpSpeed = 0.03f;
    
    duck.loadImage("duck.png");
    duck2.loadImage("duck2.png");
}

//------------------------------------------------------------------
void rectangle::draw() {
    if (isGoingLeft) {
        duck.draw(pos.x, pos.y);
    } else {
        duck2.draw(pos.x, pos.y);
    }

    
	//ofFill();
	//ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    //ofSetColor(198,246,55);
    //ofEllipse(pos.x, pos.y, 50,50);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
    
    if (pos.x > catchX) {
        isGoingLeft = true;
    } else {
        isGoingLeft = false;
    }
}
