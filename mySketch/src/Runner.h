#pragma once

class Runner :
	public GameObject
{
private:
	int currFrame;
	int numFrames;
	int startFrames[NUM_ANIM];
	int animDelay;

public:
	ofImage frames[RUNNER_FRAMES];
	bool attacking;

	Runner();
	~Runner();

	void animate(int type);
	void draw();
};

