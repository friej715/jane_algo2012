#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
    
	catchUpSpeed = ofRandom(0.003, 0.01);
    angle = ofRandom(.1, 5);
    
    fish.loadImage("fish.png");
}

//------------------------------------------------------------------
void rectangle::draw() {
    angle+=.02;
    pos.x += sin(angle);
    
        fish.draw(pos.x, pos.y, ofMap(catchUpSpeed, 0.005, 0.05, 100,20), ofMap(catchUpSpeed, 0.005, 0.05, 50, 10));

    
//	ofFill();
//    ofSetColor(198,246,55);
//    ofEllipse(pos.x, pos.y, ofMap(catchUpSpeed, 0.005, 0.05, 100,20), ofMap(catchUpSpeed, 0.005, 0.05, 50, 10));
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

}
