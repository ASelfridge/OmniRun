#include "main.h"

Runner::Runner()
{
	// not jumping or attacking
	attacking = false;

	// place at starting position
	pos = targetPos = ofVec2f(200, 200);
}


Runner::~Runner()
{

}

void Runner::update() {

}
