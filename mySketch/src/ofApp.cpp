#include "main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	background[0] = "images/background/bgLevel1.png";

	for (int i = 1; i < 13; i++) {
		runner.frames[i].load("images/runner/runnerLeft" + to_string(i) + ".png");
		runner.frames[i + 12].load("images/runner/runnerRight" + to_string(i) + ".png");
		cout << "images/runner/runnerRight" + to_string(i) + ".png\n";
	}

	endGame = false;
	currLevel = 0;

	// set all key input to false
	for (int i = 0; i < 255; i++) {
		keyDown[i] = false;
	}

	setLevel();

	attackBoostLoc[0] = ofVec2f(50, 550);
	for (int i = 0; i < NUM_BOOSTS; i++) {
		attackBoosts[i] = new GameObject();
		attackBoosts[i]->setPos(attackBoostLoc[i]);
		attackBoosts[i]->img.load("images/attackBoost.png");
		attackBoosts[i]->height = attackBoosts[i]->img.getHeight();
		attackBoosts[i]->width = attackBoosts[i]->img.getWidth();
	}


	ofSetFrameRate(60);
}

void ofApp::setLevel() {
	// load current background
	bgImage.load(background[currLevel]);

	// set time to max
	currTime = LEVEL_TIME;

	// move to next level
	currLevel++;
}

//--------------------------------------------------------------
void ofApp::update(){
	// check for arrow input and change target position
	if (keyDown[OF_KEY_LEFT]) {
		runner.targetPos.x -= runner.getSpeed().x;
		runner.animate(1);
	}
	else if (keyDown[OF_KEY_RIGHT]) {
		runner.targetPos.x += runner.getSpeed().x;
		runner.animate(2);
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

	omniUI.update(false, 0, 0);

	if (fireball.getTrigger()) {
		// Check for collision
		/* if (true)
		runner.health -= fireball.damage;
		currPos = fireball.getPos();
		fireball.target = currPos.y;
		// Time boost for omni
		currTime -= TIME_ADJUST
		if ((omni.timer - TIME_ADJUST/2.0) < 0)
		omni.timer = 0;
		else
		omni.time -= TIME_ADJUST/2.0
		*/
		fireball.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	bgImage.draw(0, 0);

	// draw UI
	omniUI.draw();

	// draw fireball
	if (fireball.getTrigger()) {
		fireball.draw();
	}

	// draw runner
	runner.draw();

	// draw attack boosts
	for (int i = 0; i < NUM_BOOSTS; i++) {
		attackBoosts[i]->draw();
	}
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
			printf("enemy");
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
