#pragma once
class Enemy :
	public GameObject
{
private:
	bool direction;
	ofVec2f origin;
public:
	Enemy();
	~Enemy();
	void start(int x, int y);
	void update();
	ofVec2f getOrigin();
	void setOrigin(ofVec2f);
	
};

