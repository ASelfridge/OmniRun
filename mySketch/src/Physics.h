#pragma once
class Physics
{
private:
	ofImage heightMap;
	int heightPoints[LEVEL_WIDTH];

public:
	Physics();
	~Physics();

	void gravity(GameObject o);
};

