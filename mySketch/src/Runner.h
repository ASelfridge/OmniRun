#pragma once

class Runner :
	public GameObject
{
private:
	bool jumping;
	bool attacking;

public:
	Runner();
	~Runner();

	void update();
};

