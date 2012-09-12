#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 10;
	myRectangle.posa.y = 100;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = 140;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
	
	isSettingA = true;
	
} 

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct);
	 
	pct += .005f;							// increase by a certain amount
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}	
	myRectangle.interpolateByPct(pct);		// go between pta and ptb

}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
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
	
    if (isSettingA) {
        myRectangle.posa.x = x;
        myRectangle.posa.y = y;
    } else {
        myRectangle.posb.x = x;
        myRectangle.posb.y = y;
    }
    
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    isSettingA = !isSettingA;
}
