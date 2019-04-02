#pragma once

class Runner :
	public GameObject
{
public:
	bool attacking;

	Runner();
	~Runner();

	void update();
};

