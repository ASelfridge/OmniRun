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
	bool collisionDetection(GameObject* o1, GameObject* o2);
};

