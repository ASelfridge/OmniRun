
#include "main.h"
Omnipotent::Omnipotent()
{

}


Omnipotent::~Omnipotent()
{
	pointCounter = MAX_AP;
	pointTimer = 0;
}

void Omnipotent::update()
{
	if (pointTimer > 0){
		pointTimer -= 1;
	}

	else if (pointTimer == 0 && pointCounter < MAX_AP){
		pointCounter += 1; 
		pointTimer = TIME_ADJUST;
	}
}
