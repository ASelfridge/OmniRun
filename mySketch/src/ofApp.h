#pragma once

class ofApp : public ofBaseApp{
	private:
		bool endGame;
		int currLevel;
		int score[2];
		int currTime;

		string background[NUM_LEVELS];
		ofImage bgImage;

		//Runner runner;
		UI omniUI;

		ofVec2f attackBoostLoc[1];

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
