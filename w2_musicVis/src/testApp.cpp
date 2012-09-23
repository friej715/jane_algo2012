#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    glass.loadSound("philip_glass.mp3");
    glass.play();
    
    musicState = 0;
    
    // setting all the music values
//    ms1_a = .6;
//    ms1_b = 1.7;
//    isInA = true;
//    lastIntA = .875;
    
    ms0.push_back(875 + ofGetElapsedTimeMillis());
    ms0.push_back(1475 + ofGetElapsedTimeMillis());
    
    ms0.push_back(3175 + ofGetElapsedTimeMillis());
    ms0.push_back(3175 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(3175 + 600 + 1700 + ofGetElapsedTimeMillis());
    ms0.push_back(3175 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(3175 + 600 + 1700 + 600 + 1700 +ofGetElapsedTimeMillis());
    ms0.push_back(3175 + 600 + 1700 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(19775 + startTime);
    ms0.push_back(20375 + startTime);
    
    ms0.push_back(22075 + ofGetElapsedTimeMillis());
    ms0.push_back(22075 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(22075 + 600 + 1700 + ofGetElapsedTimeMillis());
    ms0.push_back(22075 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(22075 + 600 + 1700 + 600 + 1700 +ofGetElapsedTimeMillis());
    ms0.push_back(22075 + 600 + 1700 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(89075 + startTime);
    ms0.push_back(89675 + startTime);
    
    ms0.push_back(91375 + ofGetElapsedTimeMillis());
    ms0.push_back(91375 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(91375 + 600 + 1700 + ofGetElapsedTimeMillis());
    ms0.push_back(22075 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());
    
    ms0.push_back(91375 + 600 + 1700 + 600 + 1700 +ofGetElapsedTimeMillis());
    ms0.push_back(91375 + 600 + 1700 + 600 + 1700 + 600 + ofGetElapsedTimeMillis());    
    
    ms2.push_back(startTime + 40775);
    ms2.push_back(startTime + 41375);
    
    ms2.push_back(startTime + 42975);
    ms2.push_back(startTime + 43375);
    
    ms2.push_back(startTime + 44775);
    ms2.push_back(startTime + 45175);
    
    ms2.push_back(startTime + 46875);
    ms2.push_back(startTime + 47575);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    background.set(12,17,23); 
    col.set(100, 100, 100);
    
    startTime = ofGetElapsedTimeMillis();
    
    ofSetVerticalSync(TRUE);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (ofGetElapsedTimeMillis() <= 11375 + startTime) {
        musicState = 0;
    } else if (ofGetElapsedTimeMillis() >= 11375 +startTime && ofGetElapsedTimeMillis() < 19700 + startTime) {
        musicState = 1;
    } else if (ofGetElapsedTimeMillis() >= 19700 + startTime && ofGetElapsedTimeMillis() < 30075 + startTime) {
        musicState = 0;
    } else if (ofGetElapsedTimeMillis() >= 30075 + startTime && ofGetElapsedTimeMillis() < 89075 + startTime) {
        musicState = 1;
    } else if (ofGetElapsedTimeMillis() >= 89075 + startTime && ofGetElapsedTimeMillis() < 100075 + startTime) {
        musicState = 0;
    } else if (ofGetElapsedTimeMillis() >= 100075 + startTime) {
        musicState = 1;
    }
    
    cout << ofGetElapsedTimeMillis() << endl;
    
    
    if (musicState == 0) { // if we're in a certain part of the music
        for (int i = 0; i < ms0.size(); i++) {
            if (abs(ofGetElapsedTimeMillis() - ms0[i]) < 50) {
                cout << "bang" << endl;
            }
        }
    }
    
    if (musicState == 1) {
        
        for (int i = 0; i < ms2.size(); i++) {
            if (abs(ofGetElapsedTimeMillis() - ms2[i]) < 50) {
                cout << "bang" << endl;
            }
        }
        
        if (ofGetElapsedTimeMillis()%4 == 0) {
            alterMS1 = true;
        } else {
            alterMS1 = false;
        }
    }
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(background);
    
    
    if (musicState == 0) {
        float xorig = ofGetWidth()/2;
        float yorig = ofGetHeight()/2;
        ofFill();
        ofSetColor(col);
        
        for (int i = 0; i < 20; i++) {
            
            
            float radius = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, ofGetWidth()) + i * .75;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            
            if (i%2==0) {
                float x = xorig + radius * -cos(angle);
                float y = yorig + radius * sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            } else {
                float x = xorig + radius * cos(angle);
                float y = yorig + radius * sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            }
        }
        
        
        for (int i = 0; i < 20; i++) {
            ofFill();
            
            float radius = ofMap(cos(ofGetElapsedTimef()), -1, 1, 10, ofGetWidth())/i;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            
            if (i%2==0) {
                float x = xorig + radius * -cos(angle);
                float y = yorig + radius * sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            } else {
                float x = xorig + radius * cos(angle);
                float y = yorig + radius * sin(angle);
                

                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            }
            
            
        }
        
        
        for (int i = 0; i < 20; i++) {
            ofFill();
            
            float radius = ofMap(cos(ofGetElapsedTimef()), -1, 1, 10, ofGetWidth()) + i * 2;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            
            if (i%2==0) {
                c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 0, 255));
                float x = xorig + radius * -cos(angle);
                float y = yorig + radius * sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            } else {
                c.setHue(ofMap(sin((ofGetElapsedTimef() + angle)/100), -1, 1, 255, 0));
                float x = xorig + radius * cos(angle);
                float y = yorig + radius * sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofEllipse(x,y,10,10);
                
            }
            
            
        }
        
        
    }
    
    
    
    
    
    if (musicState == 1) {
        
        float xorig1 = ofGetWidth()/4;
        float yorig1 = ofGetHeight()/2;
        
        
        for (int i = 0; i < 20; i++){
            
            if (i%3>0) {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef() * 5), -1, 1, -255, 0)));
            } else {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef() * 5 +1.5), -1, 1, -255, 0)));
            }
            
            float radius = 50 + i * 20;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            float x = xorig1 + radius * cos(angle);
            float y = yorig1 + radius * -sin(angle);
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(c, 100);
            ofRect(x,y,10,10);
            
        }
        
        
        float xorig2 = ofGetWidth()/2;
        float yorig2 = ofGetHeight()/2;
        
        for (int i = 0; i < 20; i++){
            
            if (i%3>0) {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()*15), -1, 1, -255, 0)));
            } else {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()*15 + 1.5), -1, 1, -255, 0)));
            }
            
            float radius = 50 + i * 20;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            float x = xorig2 + radius * cos(angle);
            float y = yorig2 + radius * -sin(angle);
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(c, 100);
            ofRect(x,y,10,10);
            
        }	
        
        float xorig3 = ofGetWidth()*.75;
        float yorig3 = ofGetHeight()/2;
        
        for (int i = 0; i < 20; i++){
            
            if (i%3>0) {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()*5), -1, 1, -255, 0)));
            } else {
                c.setBrightness(255 + (ofMap(sin(ofGetElapsedTimef()*5 +1.5), -1, 1, -255, 0)));
            }
            
            float radius = 50 + i * 20;
            float angle = ofGetElapsedTimef() * (1 + i / 10.0);
            float x = xorig3 + radius * cos(angle);
            float y = yorig3 + radius * -sin(angle);
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(c, 100);
            ofRect(x,y,10,10);
            
        }	
        
        
    }
    
    if (alterMS1) {
        c.setHsb(140, 54, 200);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    cout << ofGetElapsedTimeMillis() << endl;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}