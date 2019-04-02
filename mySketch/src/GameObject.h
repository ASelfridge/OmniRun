#pragma once
class GameObject
{
public:
	ofVec2f pos;
	ofVec2f speed;
	ofVec2f targetPos;

	
	ofImage img;

	bool triggered;
	int damage;


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

