#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "Ball.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void mouseReleased(int x, int y, int button);

	vector<ParticleSystem> systems;
	ofVec3f gravity;
    ofVec3f pos, vel;
	float lastUpdateTime;	// track frame-by-frame time diff
		
    vector<Ball> balls;
};
