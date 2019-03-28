#include "main.h"

Runner::Runner()
{
	// not jumping or attacking
	jumping = attacking = false;

	// place at starting position
	pos = targetPos = ofVec2f(10, 620);
}


Runner::~Runner()
{

}

void Runner::update() {

}
