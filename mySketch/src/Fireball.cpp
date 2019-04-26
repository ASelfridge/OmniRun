#include "main.h"



Fireball::Fireball()
{
	img.load("images/fireball.png");
	target = 0;
	setDamage(3);
	height = img.getHeight();
	width = img.getWidth();

}


Fireball::~Fireball()
{
}

void Fireball::start(int x, int y) {
	//printf("Fireball");
	target = y;
	pos.set(x - img.getWidth()/2.0, 0 - img.getHeight());
	setPos(pos);
	setTrigger();

}
void Fireball::update() {
	ofVec2f currPos = getPos();

	if (currPos.y >= target - img.getHeight()) {
		//Diappear
		setTrigger();
		pos.set(0, 0 - img.getHeight());
	}
	else {
		// Keep moving down screen
		pos.set(currPos.x, currPos.y + 5);
		setPos(pos);
	}
}

void Fireball::draw() {
	img.draw(pos.x, pos.y);

}