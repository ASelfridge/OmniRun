#pragma once
class Physics
{
private:
	ofImage heightMap;
	int heightPoint;

public:
	Physics();
	~Physics();

	void gravity(GameObject* o);
};

