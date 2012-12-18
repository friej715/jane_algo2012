#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //bg.loadImage("bg2.jpg");
    //sounds.loadSound("sound.mp3");
    
    ofBackground(43, 16, 59);
    
    ofSetVerticalSync(TRUE);
    ofEnableSmoothing();
    ofSetRectMode(OF_RECTMODE_CENTER);
    pct = 0;
    
    interval = 5000;
    startTime = ofGetElapsedTimeMillis();
    
//    sounds.setLoop(TRUE);
//    sounds.play();
    
    for (int i = 0; i < 4; i++) {
        ofColor c;
        colors.push_back(c);
    }
    
    colors[0].set(255, 252, 199);
    colors[1].set(32, 57, 84);
    colors[2].set(112, 153, 75);
    colors[3].set(200, 204, 108);
    
    for (int i = 0; i < 100; i++) {
        Firefly f;
        f.setup();
        f.col = colors[ofRandom(colors.size())];
        fireflies.push_back(f);
    }
    
    bSavePdf = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < fireflies.size(); i++) {
        fireflies[i].update(i);
        fireflies[i].interpolateByPct(pct);
    }
    
//    pct += 0.001f;
    
    cout << pct << endl;
    
//    if (ofGetElapsedTimeMillis() - startTime > interval) {
//        for (int i = 0; i < fireflies.size(); i+=2) {
//            fireflies[i].changeDir();
//            fireflies[i].alpha = 10;
//        }
//        pct = 0;
//        startTime = ofGetElapsedTimeMillis();
//    }

    for (int i = 0; i < fireflies.size(); i++) {
        if (ofGetElapsedTimeMillis() - fireflies[i].startTime > fireflies[i].interval) {
            fireflies[i].changeDir();
            fireflies[i].alpha = 10;
        }
        
        fireflies[i].pct = 0;
        fireflies[i].startTime = ofGetElapsedTimeMillis();

    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (bSavePdf == true){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
        
    }
    
    ofSetColor(255);
    //bg.draw(0, 0);
    for (int i = 0; i < fireflies.size(); i++) {
        fireflies[i].draw();
    }
    
    if( bSavePdf ){
		ofEndSaveScreenAsPDF();
        bSavePdf = false;
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == 'p'){
        
        bSavePdf = true;
    }
    
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