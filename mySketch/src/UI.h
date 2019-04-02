#pragma once
class UI
{
public:
	AbilityButton buttons[3];
	bool keyDown[255];

	UI();
	~UI();

	void update(bool mouseclick);
	void draw();
};

