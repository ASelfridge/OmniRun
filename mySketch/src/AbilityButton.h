#pragma once

class AbilityButton :
	public GameObject
{
public:

	int cooldown;
	int maxValue;
	AbilityButton();
	~AbilityButton();
	void update();
};

