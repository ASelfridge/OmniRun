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

bool Runner::getTimer(int t) {
	bool result = false;
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
		speed.x = MAX_SPEED * 2;
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
				speed.x = MAX_SPEED / 2;
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
