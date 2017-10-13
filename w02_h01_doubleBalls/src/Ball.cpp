#include "Ball.h"

// constructor
Ball::Ball() {

	
	radius = 2;

	
	color = 255;

	// random position in window
	x = ofGetMouseX();
    y = ofGetHeight();

	// random x and y speeds/directions between -10 and 10
	dirY = -5;
}

// update position, etc.
void Ball::update() {

	y+=dirY;	// move along y by amount of dirY

	// check for bounces at edges of window:


	// check top and bottom
	if (y <= radius) {
		y = radius;
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius) {
		y = ofGetHeight() - radius;
		dirY = -dirY;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawCircle(x,y, radius);		// and draw
}
