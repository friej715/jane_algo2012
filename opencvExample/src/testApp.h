#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "particle.h"
#include "vectorField.h"
#include "Enemy.h"
#include "Chaser.h"
#include "Planet.h"

#define _USE_LIVE_VIDEO

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

        #ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber 		vidGrabber;
		#else
		  ofVideoPlayer 		vidPlayer;
		#endif

        ofxCvColorImage			colorImg;

        ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage 	grayBg;
		ofxCvGrayscaleImage 	grayDiff;

        ofxCvContourFinder 	contourFinder;

		int 				threshold;
		bool				bLearnBakground;
        int scaleValue;
        bool debugVideoOn;
    
    // enemies, gamestate, general stuff
    vector <Enemy> enemies;
    int gameState;
    
    // fonts, images, and other annoying stuff
    ofTrueTypeFont headerFont;
    ofTrueTypeFont subheaderFont;
    ofImage background;
    float currentY;
    ofImage ship;
    
    // soundszz
    ofSoundPlayer hitSound;
    ofSoundPlayer rocketSound;
    ofSoundPlayer explosionSound;
    ofSoundPlayer backgroundSound;
    
    // 'sploding
    int explodeState;
    ofImage explode1;
    ofImage explode2;
    ofImage explode3;
    ofImage explode4;
    ofImage explode5;
    bool explodeShip;
    float startTimeExplode;
    float intervalExplode;
    
    // ramiro's ship positioning code
    float averageBlobX;
    float shipPosX;
    float shipPosY;
    float shipPosInFloat;
    float movementSpeed;
    float hackBlobX;
    
    // function to translate opencv image into usable data
    float moveShipValue();
    
    // particle effects 'cause let's make this our algo final
    vector <particle> particles;
    vector <float> particleAlphas;
    vectorField VF; // helps randomize movement of smoke particles
    
    // collision
    bool shipIsHit;    
    
    // shaky screen and text
    bool screenIsShaking;
    int screenShakeX;
    int screenShakeY;
    int timeLeftToShake; // if we get hit by something (or multiple things), we should shake for a while
    int shakeStartTime; // the start of our shaking interval
    float endscreenAngle;
    float noiseForEndscreen;
    
    // bring the pain motherfuckers
    float health;
    bool shipIsSmoking; // whether smoke should be coming off the ship
    
    
    // noise background
    void makeNoise();
    float scrollX;
    float scrollY;
    
    // black hoooooooolesssszzzz
    vector<ofPoint> blackHolePoints;
    vector<particle> blackHoleParticles;
    
    // stars
    vector<ofPoint> starPoints;
    vector<float> starDepth;
    
    // chasers and planets
    vector<Chaser> chasers;
    vector<Planet> planets;
    
    
    
};

