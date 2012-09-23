#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    // music
    ofSoundPlayer glass;
    
    // gamestate, but for music
    int musicState;
    
    // want to store intervals for the different sub-pieces of the music
    //int ms1_a; // between the two notes
    //int ms1_b; // between each set of notes
    //bool isInA;
    //int lastIntA;
    //int lastIntB;
    
    
    vector<int> ms0;
    vector<int> ms2;
    
    bool alterMS0;
    bool alterMS1;
    
    int startTime; // overall start
    
    ofColor c;
    ofColor col;
    ofColor background;
    
    
    // ms1 at 11375, ends 19875
    
    
    /* Note the times here for when the music changes:
     13035
     21558
     31137
     40153
     48188
     56685
     64844
     73697
     81713
     90442
     101313
    */
    
    /* Music consists of three parts:
     - bb,bb,bb,bb (musicstate = 0)
     - babababababababababababababababa (musicstate = 1)
     - ba,ba,ba,bc (musicstate = 2)
    */
    
};
