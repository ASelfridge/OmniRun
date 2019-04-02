#include "main.h"



UI::UI()
{
	buttons[0].img.load("images/0.5x/fireballAsset 1.png");



}

UI::~UI()
{
}

void UI::update(bool mouseclick) {
	if (mouseclick) {
		printf("Clicked");
	}
	else {
		printf("updating");
	}
}

void UI::draw() {
	for (int i = 0; i < 3; i++)
	{
		buttons[i].img.draw(0, 0);
	}

}