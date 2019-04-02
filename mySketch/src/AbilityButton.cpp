#include "main.h"

AbilityButton::AbilityButton() {
	maxValue = MAX_AP;
	cooldown = 0;
}
AbilityButton::~AbilityButton() {

}

void AbilityButton::update() {
	if (cooldown == 0 && maxValue < MAX_AP) {
		triggered = true;
	}
	else {
		cooldown -= 1;
	}
}