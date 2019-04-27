#pragma once
class GameObject
{
protected:
	ofVec2f pos;
	ofVec2f speed;

	bool triggered;
	int damage;
	int health;

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
	void setHealth(int h);

	ofVec2f getPos();
	bool getTrigger();
	ofVec2f getSpeed();
	int getDamage();
	int getHealth();
};

