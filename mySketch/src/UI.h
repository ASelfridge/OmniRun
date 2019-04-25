#pragma once
class UI
{
public:
	AbilityButton buttons[3];
	int buttonWidth;
	int buttonHeight; 
	int selectedButton;

	bool keyDown[255];
	
	UI();
	~UI();

	bool update(bool mouseClick, int x, int y);
	void draw();
};

