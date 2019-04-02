#include "main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	background[0] = "images/background/bgLevel1.png";

	endGame = false;
	currLevel = 0;

	// set all key input to false
	for (int i = 0; i < 255; i++) {
		keyDown[i] = false;
	}

	setLevel();
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
	}
	if (keyDown[OF_KEY_RIGHT]) {
		runner.targetPos.x += runner.getSpeed().x;
	}
	// if space key is pressed
	if (keyDown[' '] && !runner.jumping) {
		// initate runner jump
		runner.jumping = true;
		runner.t = 0;
		runner.y0 = runner.getPos().y;
		runner.v0 = runner.getSpeed().y;
	}

	// apply gravity to player
	physics.gravity(&runner);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	bgImage.draw(0, 0);

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
