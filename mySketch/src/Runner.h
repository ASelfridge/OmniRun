#pragma once

class Runner :
	public GameObject
{
private:
	int currFrame;
	int numFrames;
	int startFrames[NUM_ANIM];
	int animDelay;
	int activeTimers[NUM_TIMERS];
	int health;

public:
	ofImage frames[RUNNER_FRAMES];
	bool attacking;

	Runner();
	~Runner();

	bool getTimer(int t);
	int getHealth();
	void setHealth(int h);
	void animate(int type);
	void draw();
	void startTimer(int t);
	void updateTimers();
};

