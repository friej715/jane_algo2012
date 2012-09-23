#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
    
	catchUpSpeed = 0.1f;
    radius = 30;
    
    pos.set(0,0);
	prevPos.set(0,0);
    
    
}

//------------------------------------------------------------------
void rectangle::draw(int i) {
    whichOne = i;
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    
    
    ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        //ofRotateZ(angle * RAD_TO_DEG);
        ofEllipse( 0,0, radius,radius);
    if (i == 0) {
        ofSetColor(255);
        ofEllipse(-5, -5, 10, 10);
        ofEllipse(5, -5, 10, 10);
        
        ofSetColor(0);
        
        //ofRotateZ(angle*RAD_TO_DEG);
        
        p1.x = 2*cos(angle) - 5;
        p1.y = 2*sin(angle) - 5;
        
        p2.x = 2*cos(angle) + 5;
        p2.y = 2*sin(angle) - 5;
        
        
        ofEllipse(p1.x, p1.y, 5, 5);
        ofEllipse(p2.x, p2.y, 5, 5);
    }
	ofPopMatrix();
    
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
        
	pos.x = (catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x) + cos(ofGetElapsedTimef() * whichOne); 
	pos.y = (catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y); 
    
	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);
    
	prevPos.x = pos.x;
	prevPos.y = pos.y;
    
}


void rectangle::breathe(float i) {
    
    float tempSine = -sin(ofGetElapsedTimef());
    float mappedSine = ofMap(tempSine, -1, 1,40, 70);
    
    radius = mappedSine;
    
}