#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
    ofEnableAlphaBlending();
    
    c.setHsb(ofRandom(255), 255, 255, 150);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	for (int i = 0; i < 25; i++){
        ofFill();
        
        float radius = 50 + i * 20;
		float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        
        if (i%3>0) {
            c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()), -1, 1, -100, 0)));
        } else {
            c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()+1.5), -1, 1, -100, 0)));
        }
        
//        if (i%4 == 0) {
//            //c.set(255 + (ofMap(sin(ofGetElapsedTimef()), -1, 1, -255, 0)));
//            float x = xorig + radius * -cos(angle);
//            float y = yorig + radius * sin(angle);
//            
//            ofSetColor(c);
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofEllipse(x,y,10,10);
//        } else if (i%3==0) {
//            float x = xorig + radius * -cos(angle) *-1;
//            float y = yorig + radius * -sin(angle) *-1;
//            
//            ofSetColor(c);
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofEllipse(x,y,10,10);
       /* } else*/ 
        
        if (i%2==0) {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 0, 255));
            float x = xorig + radius * -cos(angle);
            float y = yorig + radius * -sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        } else {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 255, 0));
            float x = xorig + radius * cos(angle);
            float y = yorig + radius * -sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        }
        
	
	}	
	
	
    for (int i = 0; i < 13; i++) {
        ofFill();
        
        float radius = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, ofGetWidth()) + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        
        if (i%2==0) {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 0, 255));
            float x = xorig + radius * -cos(angle);
            float y = yorig + radius * sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        } else {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 255, 0));
            float x = xorig + radius * cos(angle);
            float y = yorig + radius * sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        }
        
        
    }
    
    for (int i = 0; i < 13; i++) {
        ofFill();
        
        float radius = ofMap(cos(ofGetElapsedTimef()), -1, 1, 10, ofGetWidth()) + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        
        if (i%2==0) {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 0, 255));
            float x = xorig + radius * -cos(angle);
            float y = yorig + radius * sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        } else {
            c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 255, 0));
            float x = xorig + radius * cos(angle);
            float y = yorig + radius * sin(angle);
            
            ofSetColor(c);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofEllipse(x,y,10,10);
            
        }
        
        
    }
    

	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

