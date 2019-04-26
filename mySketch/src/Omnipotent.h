#pragma once
class Omnipotent :
	public GameObject
{
public:
	int pointTimer;
	int pointCounter;
	Omnipotent();
	~Omnipotent();
	void update();
};

