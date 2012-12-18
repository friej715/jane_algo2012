#ifndef CHASER_H
#define CHASER_H

#include "ofMain.h"

class Chaser
{
    public:
			
        Chaser();
		virtual ~Chaser(){};


        void update(int shipX, int shipY);
        void draw();

		float posX;
		float posY;
		float pos2X;
		float pos2Y;
		float pos3X;
		float pos3Y;
		float pos4X;
		float pos4Y;
		int size;
		int tail2Size;
		int tail3Size;
		int tail4Size;
		ofColor myColor;
		float speed;
		float catchUpSpeed;
		float tailCatchUpSpeed;
		float eyeAngle;
		float eyeHeight;
		float eyeHeightPre;
		bool blinking;
		bool blinkClosing;
		float totalHeight;
		int blinkTimer;
};

#endif // CHASER_H
