#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(TRUE);
    ofBackground(0);
    
    startTime = ofGetElapsedTimeMillis();
    interval = 4000;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (ofGetElapsedTimeMillis() > startTime + interval) {
        
        particles.clear();
        
        float x = ofRandom(100, ofGetWidth() - 100);
        float y = ofRandom(ofGetHeight()/2);
        
        for (int i = 0; i < 360; i++) {
            float tempAngle = ofDegToRad(i);
            
            Particle p;
            p.c.setSaturation(255);
            
            p.brightness = 255;
            p.c.setBrightness(p.brightness);
            
            // let's set up different types of fireworks yaaaaay!
            if (fireworkType%3 == 0) { // regular circle-styles
                p.c.setHue(i);
                
                float vx = cos(tempAngle) * (ofRandom(3));
                float vy = sin(tempAngle) * (ofRandom(3));
                p.setInitialCondition(x,y,vx, vy);
            }
            
            if (fireworkType%4 == 1) { // spiral-styles
                p.c.setHue(sin(i)*100);
                
                float vx = cos(tempAngle) * (i * ofRandom(.001, .005));
                float vy = sin(tempAngle) * (i * ofRandom(.001, .005));
                p.setInitialCondition(x,y,vx, vy); 
            }
            
            if (fireworkType%4 == 2) { // explodey-styles
                p.c.setHue(120/cos(i) + 50);
                
                float vx = sin(tempAngle) * ofRandom(2, 3);
                float vy = sin(tempAngle) * ofRandom(1);
                p.setInitialCondition(x,y,vx, vy); 
            }        
            
            particles.push_back(p); 
        }
        
        fireworkType++;
        
        if (fireworkType > 3) {
            fireworkType = 0;
        }
        
        
        startTime = ofGetElapsedTimeMillis();
    }
    
    
    
    if (particles.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            particles[i].resetForce();
            particles[i].addForce(0,0.02);  // gravity
            particles[i].addDampingForce();
            particles[i].update();
        }
    }
    cout << particles.size();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (particles.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            particles[i].draw();
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
//    particles.clear();
//    
//    for (int i = 0; i < 360; i++) {
//        float tempAngle = ofDegToRad(i);
//        
//        Particle p;
//        p.c.setSaturation(255);
//        
//        p.brightness = 255;
//        p.c.setBrightness(p.brightness);
//        
//        // let's set up different types of fireworks yaaaaay!
//        if (fireworkType%3 == 0) { // regular circle-styles
//            p.c.setHue(i);
//            
//            float vx = cos(tempAngle) * (ofRandom(3));
//            float vy = sin(tempAngle) * (ofRandom(3));
//            p.setInitialCondition(mouseX,mouseY,vx, vy);
//        }
//        
//        if (fireworkType%4 == 1) { // spiral-styles
//            p.c.setHue(sin(i)*100);
//
//            float vx = cos(tempAngle) * (i * ofRandom(.001, .005));
//            float vy = sin(tempAngle) * (i * ofRandom(.001, .005));
//            p.setInitialCondition(mouseX,mouseY,vx, vy); 
//        }
//        
//        if (fireworkType%4 == 2) { // explodey-styles
//            p.c.setHue(120/cos(i) + 50);
//            
//            float vx = sin(tempAngle) * ofRandom(2, 3);
//            float vy = sin(tempAngle) * ofRandom(1);
//            p.setInitialCondition(mouseX,mouseY,vx, vy); 
//        }        
//        
//        particles.push_back(p); 
//    }
//    
//    fireworkType++;
//    
//    if (fireworkType > 3) {
//        fireworkType = 0;
//    }
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