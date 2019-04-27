#include "main.h"

Runner::Runner()
{
	frames[0].load("images/runner/runnerStand.png");
	health = MAX_HEALTH * 100;
	// not jumping or attacking
	attacking = false;

	// place at starting position
	pos = targetPos = ofVec2f(200, 200);

	numFrames  = currFrame = 0;

	startFrames[0] = 0;
	startFrames[1] = 1;
	startFrames[2] = 13;
	startFrames[3] = 25;
	startFrames[4] = 31;
	startFrames[5] = 37;
	
	animDelay = 0;

	// set timers to inactive
	for (int i = 0; i < NUM_TIMERS; i++) {
		activeTimers[i] = -1;
	}
}


Runner::~Runner()
{

}

void Runner::animate(int type) {
	// if not standing still
	if (type > 0) {
		// don't animate if delay still in place
		if (animDelay > 0) {
			animDelay--;
		}
		else {
			// if this type of animation is already underway
			if (currFrame >= startFrames[type] && currFrame < startFrames[type + 1]) {
				// increment frame
				currFrame++;
				// if at max frames for this type of animation
				if (currFrame == startFrames[type + 1]) {
					// if left or right animation start back at second frame in cycle
					if (type == 1 || type == 2) {
						currFrame = startFrames[type] + 2;
					}
					else {
						// otherwise must be attack animation so freeze final frame
						currFrame--;
						// change attack bool back
						attacking = false;
					}
				}
				// check if on punch frame in attack animation
				if ((type == 3 || type == 4) && currFrame == startFrames[type + 1] - 2) {
					attacking = true;
				}
				
			}
			else {
				// otherwise start this animation type
				currFrame = startFrames[type];
				attacking = false;
			}
			// add delay to animation so that frames are more clear
			animDelay = 2;
		}
	}
	else {
		currFrame = startFrames[type];
		attacking = false;
	}
	// change width and height to accomodate new image in animation
	width = frames[currFrame].getWidth();
	height = frames[currFrame].getHeight();
}

void Runner::draw() {
	// draw current frame in animation cycle
	frames[currFrame].draw(pos.x, pos.y);
}

bool Runner::getTimer(int t) {
	bool result = false;
	// check if timer is not set
	if (activeTimers[t] != -1) {
		result = true;
	}
	return result;
}

void Runner::startTimer(int t) {
	// if attack boost
	if (t == 0) {
		damage = MAX_DAMAGE * 2;
	}
	// if speed gate
	if (t == 1) {
		speed.x = MAX_SPEED + 2;
	}
	// set timer as active
	activeTimers[t] = ACTIVE_TIMER;
}

void Runner::updateTimers() {
	for (int i = 0; i < NUM_TIMERS; i++) {
		if (activeTimers[i] == 0 ) {
			// if attack boost
			if (i == 0) {
				damage = MAX_DAMAGE / 2;
			}
			// if speed gate
			if (i == 1) {
				speed.x = MAX_SPEED - 2;
			}
			// set inactive
			activeTimers[i] = -1;
		}
		// if timer is active, decrease it
		else if(activeTimers[i] > 0){
			activeTimers[i]--;
		}
	}
}

