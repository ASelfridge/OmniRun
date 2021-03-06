#pragma once

class ofApp : public ofBaseApp{
	private:
		bool startGame;
		bool endGame;
		string winner;
		int currLevel;
		int score[2];
		int currTime;
		int enemyCounter;
		Enemy *enemies = new Enemy[5];

		ofImage startScreen;
		ofImage endScreen;

		string background[NUM_LEVELS];
		ofImage bgImage;

		Physics physics;
		Runner runner;

		ofVec2f attackBoostLoc[NUM_BOOSTS];
		GameObject* attackBoosts[NUM_BOOSTS];

		ofVec2f speedGateLoc[NUM_SPEEDGATES];
		GameObject* speedGates[NUM_SPEEDGATES];

		GameObject finishFlag;

		UI omniUI;
		Omnipotent omni;
		Fireball fireball;


		bool keyDown[255];

	public:

		void setup();
		void update();
		void draw();

		void setLevel();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
