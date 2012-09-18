#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    bg.loadImage("Aquarium.png");
	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	for (int i = 0; i < 5; i++) {
        rectangle f;
        fish.push_back(f);
    }
    
//    for (int x = 0; x < ofGetWidth(); x+=50) {
//        for (int y = 0; y < ofGetHeight(); y+=50) {
//            water w;
//            w.setup(x, y);
//            waves.push_back(w);
//        }
//    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < 5; i++) {
        if (foods.size() > 0) {
            int d = ofGetWidth();
            int f;
            
            for (int j = 0; j < foods.size(); j++) {
                if (foods[j].isEaten == false) {
                    int ds = ofDist(fish[i].pos.x, fish[i].pos.y, foods[j].loc.x, foods[j].loc.y);
                    if (ds < d) {
                        d = ds;
                        f = j;
                    }
                }
            }
            fish[i].xenoToPoint(foods[f].loc.x, foods[f].loc.y);
        } else {
            fish[i].xenoToPoint(mouseX, mouseY);
        }
        
    }
    
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < foods.size(); j++) {
            if (ofDist(fish[i].pos.x, fish[i].pos.y, foods[j].loc.x, foods[j].loc.y) < 40) {
                foods[j].isEaten = true;
            }
        }
    }
    
    
    
    for (int i = 0; i < foods.size(); i++) {
        foods[i].update();
        if (foods[i].isEaten) {
            foods.erase(foods.begin()+i);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    ofSetColor(255);
    bg.draw(0, 0);
    
    for (int i = 0; i < waves.size(); i++) {
        waves[i].draw();
    }
    
    for (int i = 0; i < 5; i++) {
        fish[i].draw();
    }
    
    for (int i = 0; i < foods.size(); i++) {
        foods[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){
    food f;
    f.setup(mouseX, mouseY);
    foods.push_back(f);
}
