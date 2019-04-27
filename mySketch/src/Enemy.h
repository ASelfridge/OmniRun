#pragma once
class Enemy :
	public GameObject
{
private:
	bool direction;
	ofVec2f origin;
public:
	bool isAlive;
	Enemy();
	~Enemy();
	void start(int x, int y);
	void update(int playerX);
	ofVec2f getOrigin();
	void setOrigin(ofVec2f);
	void draw();
	
};

