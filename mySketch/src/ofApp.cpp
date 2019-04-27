#include "main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load level image
	background[0] = "images/background/bgLevel_1.png";

	// load runner animation images
	for (int i = 1; i < 13; i++) {
		runner.frames[i].load("images/runner/runnerLeft" + to_string(i) + ".png");
		runner.frames[i + 12].load("images/runner/runnerRight" + to_string(i) + ".png");
	}
	for (int i = 0; i < 6; i++) {
		runner.frames[i + 25].load("images/runner/runnerAttackRight" + to_string(i + 1) + ".png");
		runner.frames[i + 31].load("images/runner/runnerAttackLeft" + to_string(i + 1) + ".png");
	}

	// starting variables
	enemyCounter = 0;
	endGame = false;
	currLevel = 0;

	// setup attack boosts
	attackBoostLoc[0] = ofVec2f(506, 161);
	for (int i = 0; i < NUM_BOOSTS; i++) {
		attackBoosts[i] = new GameObject();
		attackBoosts[i]->setPos(attackBoostLoc[i]);
		attackBoosts[i]->img.load("images/attackBoost.png");
		attackBoosts[i]->height = attackBoosts[i]->img.getHeight();
		attackBoosts[i]->width = attackBoosts[i]->img.getWidth();
	}

	// setup speed gates
	speedGateLoc[0] = ofVec2f(680, 380);
	for (int i = 0; i < NUM_SPEEDGATES; i++) {
		speedGates[i] = new GameObject();
		speedGates[i]->setPos(speedGateLoc[i]);
		speedGates[i]->img.load("images/speedGate.png");
		speedGates[i]->height = speedGates[i]->img.getHeight();
		speedGates[i]->width = speedGates[i]->img.getWidth();
	}

	setLevel();

	// set all key input to false
	for (int i = 0; i < 255; i++) {
		keyDown[i] = false;
	}

	// set frame rate
	ofSetFrameRate(60);
}

void ofApp::setLevel() {
	// load current background
	bgImage.load(background[currLevel]);

	// set time to max
	currTime = LEVEL_TIME;

	// move to next level (removed)
	//currLevel++;
}

//--------------------------------------------------------------
void ofApp::update(){
	// check for arrow input and change target position
	if (keyDown[OF_KEY_LEFT]) {
		runner.targetPos.x = runner.getPos().x - runner.getSpeed().x;
		if (!runner.jumping) {
			runner.animate(1);
		}
	}
	else if (keyDown[OF_KEY_RIGHT]) {
		runner.targetPos.x = runner.getPos().x + runner.getSpeed().x;
		if (!runner.jumping) {
			runner.animate(2);
		}
	}

	// check for attack key input and animate accordingly
	else if (keyDown[OF_KEY_UP]) {
		runner.animate(3);
	}
	else if (keyDown[OF_KEY_DOWN]) {
		runner.animate(4);
	}
	else {
		// otherwise must be standing still
		runner.animate(0);
	}

	// if space key is pressed
	if (keyDown[' '] && !runner.jumping) {
		// initate runner jump
		runner.jumping = true;
		runner.t = 0;
		runner.y0 = runner.getPos().y;
		runner.v0 = runner.getSpeed().y;
	}

	// apply gravity to runner
	physics.gravity(&runner);

	// update runner timers
	runner.updateTimers();

	// check for collision with attack boosts
	for (int i = 0; i < NUM_BOOSTS; i++) {
		if (physics.collisionDetection(&runner, attackBoosts[i]) && !runner.getTimer(0)) {
			runner.startTimer(0);
			attackBoosts[i]->setPos(ofVec2f(-100, -100));
		}
	}

	// check for collision with speed gates
	for (int i = 0; i < NUM_SPEEDGATES; i++) {
		if (physics.collisionDetection(&runner, speedGates[i]) && !runner.getTimer(1)) {
			runner.startTimer(1);
		}
	}

	omniUI.update(false, 0, 0);

	if (fireball.getTrigger()) {
		// Check for collision
		if (physics.collisionDetection(&runner, &fireball)){
			int currHealth = runner.getHealth();
			runner.setHealth(currHealth-= fireball.getDamage());
			ofVec2f currPos = fireball.getPos();
			fireball.target = currPos.y;
			
			// Time boost for omni
			currTime -= TIME_ADJUST;
			/*if ((omni.timer - TIME_ADJUST / 2.0) < 0)
				omni.timer = 0;
			else
				omni.time -= TIME_ADJUST / 2.0*/
		}
		
		fireball.update();
	}

	// update enemies
	for (int i = 0; i < enemyCounter; i++) {
		if (enemies[i].isAlive) {
			enemies[i].update(runner.getPos().x);
			physics.gravity(&enemies[i]);
			// check if player is attacking enemy
			if (physics.collisionDetection(&runner, &enemies[i]) && runner.attacking) {
				enemies[i].setHealth(enemies[i].getHealth() - runner.getDamage());
			}
			else if (physics.collisionDetection(&runner, &enemies[i])) {
				int currHealth = runner.getHealth();
				runner.setHealth(currHealth -= enemies[i].getDamage());
			}
		}
	}

	// decrease level timer
	currTime--;
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	bgImage.draw(0, 0);

	// draw UI
	omniUI.draw(runner, currTime);

	// draw fireball
	if (fireball.getTrigger()) {
		fireball.draw();
	}
	// draw enemies
	for (int i = 0; i < enemyCounter; i++) {
		if (enemies[i].isAlive) {
			enemies[i].draw();
		}
	}


	// draw attack boosts
	for (int i = 0; i < NUM_BOOSTS; i++) {
		attackBoosts[i]->draw();
	}

	// draw speed gates
	for (int i = 0; i < NUM_SPEEDGATES; i++) {
		speedGates[i]->draw();
	}


	// draw runner
	runner.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyDown[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//printf("%d, %d", x, y);
	// Check if mouse click was on button
	bool onButton = omniUI.update(true, x, y);

	// If not and a button is selected, perform ability
	if (!onButton && omniUI.selectedButton > -1) {
		switch (omniUI.selectedButton)
		{
		case 0: // Fireball
			fireball.start(x, y);
			omniUI.selectedButton = -1;
			break;
		case 1: // Enemy
			if (enemyCounter <= 4){
				enemies[enemyCounter].start(x, y);
				enemyCounter++;
			}
			break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
