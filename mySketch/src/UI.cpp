#include "main.h"



UI::UI()
{
	buttons[0].img.load("images/0.png");
	buttons[1].img.load("images/1.png");
	buttonWidth = buttons[0].img.getWidth();
	buttonHeight = buttons[0].img.getHeight();
	selectedButton = -1;
	
}

UI::~UI()
{
}

bool UI::update(bool mouseClick, int x, int y) {
	int width = 0;
	
	// Update the button selected 
	if (mouseClick)
	{
		for (int i = 1; i <= NUM_BUTTONS; i++)
		{	// Check that click is within button borders
			if (width <= x && x <= buttonWidth * i) {
				if (0 <= y && y <= buttonHeight) {
					//printf("%d between %d and %d, button %d \n", x, width, buttonWidth*i, i);
					
					// Update and see if trigger gets flipped (means cooldown = 0)
					buttons[i-1].update(true);
					
					if (buttons[i - 1].getTrigger()) {
						selectedButton = i - 1;
						buttons[selectedButton].setTrigger();
						return true;
					}
				}
			}
			width += buttonWidth;
		}
		
	}

	// Update each button's cooldown
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons[i].update(false);
		if (buttons[i].cooldown > 0) {
			buttons[i].img.load("images/" + to_string(i) + "_grey.png");
		}
		else {
			buttons[i].img.load("images/" + to_string(i) + ".png");
		}
	}
	return false;
	
}

void UI::draw() {
	float width = 0;
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons[i].img.draw(width, 0);
		width += buttonWidth;
	}
	
}