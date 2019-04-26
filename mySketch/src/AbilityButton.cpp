#include "main.h"

AbilityButton::AbilityButton() {
	maxValue = MAX_AP;
	cooldown = 0;
	
	
}
AbilityButton::~AbilityButton() {

}

void AbilityButton::update(bool clicked) {
	if (cooldown == 0 && clicked) {
		setTrigger();
		cooldown = TIME_ADJUST;
		//bool triggerValue = getTrigger();
		//printf("Triggered %d \n", triggerValue);
	}
	else if (cooldown > 0){
		cooldown -= 1;
		//printf("cooldown = %d \n", cooldown);
	}
}