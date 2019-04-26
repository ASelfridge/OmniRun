#include "main.h"


Physics::Physics()
{
	// load height map
	heightMap.load("images/background/bgLvl1_heightMap.png");
	heightPoint = LEVEL_HEIGHT;
}

Physics::~Physics()
{
}

void Physics::gravity(GameObject* o) {
	ofVec2f objPos = o->getPos();
	int targetX = o->targetPos.x;
	if (o->targetPos.x > objPos.x) {
		targetX = o->targetPos.x + o->width;
	}

	//cout << "currPos: " << objPos.x << "||| targetPos: " << targetX << "\n";

	int heightPoint = 0;
	ofColor currPixel;
	// check colour of each vertical pixel at target x position, starting from objects current y position
	for (int i = objPos.y + o->height - 5; i < LEVEL_HEIGHT; i++) {
		currPixel = heightMap.getColor(targetX, i);
		// if theres no ground at this x location
		if (i == LEVEL_HEIGHT - 1) {
			heightPoint = 0;
		}
		else if (currPixel.r == 0 && currPixel.g == 0 && currPixel.b == 0) {
			// find the closest white pixel
			ofColor abovePixel;
			abovePixel = heightMap.getColor(targetX, i - 5);
			if (abovePixel.r != 0 && abovePixel.g != 0 && abovePixel.b != 0) {
				heightPoint = i;
				break;
			}
		}
	}

	// check horizontal/incline movement
	int dy = heightPoint - (objPos.y + o->height);
	if (dy > -5) {
		objPos.x = o->targetPos.x;
		if (dy < 5) {
			objPos.y += dy;
		}
	}


	if (o->jumping) {
		objPos.y = o->y0 - o->v0 * o->t + 0.5 * GRAVITY * o->t*o->t;
		o->t += 0.2;

		if (objPos.y > heightPoint - o->height) {
			objPos.y = heightPoint - o->height;
			o->jumping = false;
		}
	}

	// if fall
	else {
		if (objPos.y < heightPoint - o->height) {
			o->jumping = true;
			o->t = o->v0 = 0;
			o->y0 = objPos.y;
		}
	}

	o->setPos(objPos);
}

bool Physics::collisionDetection(GameObject* o1, GameObject* o2) {
	bool result = false;

	if (o2->getPos().x < o1->getPos().x + o1->width && o2->getPos().x + o2->width > o1->getPos().x && o2->getPos().y < o1->getPos().y + o2->height && o2->getPos().y +o2->height > o1->getPos().y) {
		result = true;
	}
	
	return result;
}
