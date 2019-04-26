#include "main.h"



Enemy::Enemy()
{
	img.load("images/enemy.png");
	setDamage(2);
}


Enemy::~Enemy()
{
}

void Enemy::start(int x, int y) {
	origin.set(x - img.getWidth() / 2.0, y - img.getHeight());
	setOrigin(origin);
	setPos(origin);
}

ofVec2f Enemy::getOrigin() {
	return origin;
}
void Enemy::setOrigin(ofVec2f position) {
	origin.set(position);
}