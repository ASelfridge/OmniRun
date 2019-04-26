#pragma once

class Fireball :
	public GameObject
{
public:
	int target;

	Fireball();
	~Fireball();
	void start(int x, int y);
	void update();
	void draw();
};

