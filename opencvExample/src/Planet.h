#ifndef PLANET_H
#define PLANET_H

#include "ofMain.h"

class Planet
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        Planet();
		virtual ~Planet(){};


        void update();
        void draw();

		float posX;
		float posY;
		int size;
		ofColor myColor;
		float speedY;
		float speedX;
		float posXOriginal;
		float moonX;
		float moonY;
		float moonSize;
    
    ofImage image;
};

#endif // ENEMY_H
