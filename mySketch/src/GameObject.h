#pragma once
class GameObject
{
protected:
	ofVec2f pos;
	ofVec2f speed;

	bool triggered;
	int damage;

public:
	ofImage img;
	ofVec2f targetPos;

	// for physics
	int y0;
	int v0;
	float t;
	int height;
	int width;
	bool jumping;

	GameObject();
	~GameObject();

	void draw();
	void setPos(ofVec2f target);
	void setTrigger();
	void setSpeed(int s);
	void setDamage(int d);

	ofVec2f getPos();
	bool getTrigger();
	ofVec2f getSpeed();
	int getDamage();
};

