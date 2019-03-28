#include "main.h"


Physics::Physics()
{
	// load height map
	heightMap.load("images/background/bgLevel1.png");
	// set height of each collidable pixel in the height map
	ofColor currPixel;
	for (int i = 0; i < LEVEL_WIDTH; i++) {
		for (int j = 0; j < LEVEL_HEIGHT; j++) {
			currPixel = heightMap.getColor(i, j);
			// if theres no ground at this x location
			if (j == LEVEL_HEIGHT - 1) {
				heightPoints[i] = LEVEL_HEIGHT;
			}
			// if pixel is black (collidable)
			else if (currPixel.r == 0 && currPixel.g == 0 && currPixel.b == 0) {
				// set point in array as height
				heightPoints[i] = j;
				break;
			}
		}
	}
}

Physics::~Physics()
{
}

void Physics::gravity(GameObject o) {
	
}
