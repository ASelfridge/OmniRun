#include "main.h"

Runner::Runner()
{
	frames[0].load("images/runner/runnerStand.png");

	// not jumping or attacking
	attacking = false;

	// place at starting position
	pos = targetPos = ofVec2f(200, 200);

	numFrames  = currFrame = 0;

	startFrames[0] = 0;
	startFrames[1] = 1;
	startFrames[2] = 13;
	startFrames[3] = 25;
	
	animDelay = 0;
}


Runner::~Runner()
{

}

void Runner::animate(int type) {
	// if not standing still
	if (type > 0) {
		if (animDelay > 0) {
			animDelay--;
		}
		else {
			//cout << currFrame << "\n";
			// if this type of animation is already underway
			if (currFrame >= startFrames[type] && currFrame < startFrames[type + 1]) {
				currFrame++;
				// increment frame if not at max for this type of animation
				if (currFrame == startFrames[type + 1]) {
					currFrame = startFrames[type] + 2;
				}
				
			}
			else {
				// start this animation type
				currFrame = startFrames[type];
			}
			animDelay = 2;
		}
	}
	else {
		currFrame = startFrames[type];
	}
	// change width to accomodate new image in animation
	width = frames[currFrame].getWidth();
	height = frames[currFrame].getHeight();
}

void Runner::draw() {
	//cout << height << "\n";
	frames[currFrame].draw(pos.x, pos.y);
}
