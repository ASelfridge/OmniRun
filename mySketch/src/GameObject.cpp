#include "main.h"

GameObject::GameObject()
{
	damage = MAX_DAMAGE;
	speed = ofVec2f(MAX_SPEED, 50);
	height = width = 10;
	pos = targetPos = ofVec2f(0, 0);
	jumping = false;
}


GameObject::~GameObject()
{
}

void GameObject::draw() {
	ofSetColor(255, 0, 0);
	ofRect(pos.x, pos.y, height, width);
	ofSetColor(255, 255, 255);
}

void GameObject::setPos(ofVec2f target) {
	pos = target;
}

void GameObject::setTrigger() {
	triggered = !triggered;
}

void GameObject::setSpeed(int s) {

}

void GameObject::setDamage(int d) {
	damage = d;
}

ofVec2f GameObject::getPos() {
	return pos;
}

bool GameObject::getTrigger() {
	return triggered;
}

ofVec2f GameObject::getSpeed() {
	return speed;
}

int GameObject::getDamage() {
	return damage;
}