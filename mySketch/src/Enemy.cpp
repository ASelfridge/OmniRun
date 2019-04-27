#include "main.h"



Enemy::Enemy()
{
	img.load("images/enemy.png");
	height = img.getHeight();
	isAlive = true;
}


Enemy::~Enemy()
{
}

void Enemy::start(int x, int y) {
	origin.set(x - img.getWidth() / 2.0, y - img.getHeight());
	setOrigin(origin);
	setPos(origin);
}

void Enemy::update(int playerX) {
	ofVec2f currPos = getPos();
	// check if health is 0 and draw off screen if so
	if (health <= 0) {
		isAlive = false;
	}
	else if (playerX <= (currPos.x + MAX_DISTANCE) && playerX >= (currPos.x - MAX_DISTANCE)) {
		// Player close, attack mode
		if (playerX < currPos.x) {
			// Move left
			targetPos.x = currPos.x - (MAX_SPEED / 2.0);
		}
		else if (playerX > currPos.x) {
			// Move right
			targetPos.x = currPos.x + (MAX_SPEED / 2.0);
		}
	}
	else {
		// Sentry Mode
		if ((origin.x + MAX_DISTANCE) <= currPos.x) {
			// Swap Directions
			direction = false;
		}
		else if ((origin.x - MAX_DISTANCE) >= currPos.x) {
			direction = true;
		}
		if (direction) {
			// Move right
			targetPos.x = currPos.x + (MAX_SPEED / 2.0);
		}
		else {
			// Move left
			targetPos.x = currPos.x - (MAX_SPEED / 2.0);
		}
	}
}
ofVec2f Enemy::getOrigin() {
	return origin;
}
void Enemy::setOrigin(ofVec2f position) {
	origin.set(position);
}
void Enemy::draw() {
	img.draw(pos.x, pos.y);
}