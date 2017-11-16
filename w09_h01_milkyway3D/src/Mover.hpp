//
//  Mover.hpp
//  Attraction
//
//  Created by Tyler on 10/5/17.
//  Modified by Jacqueline on 10/12/17.
//

#pragma once
#include "ofMain.h"

class Mover {
	
public:
	
	Mover();
	~Mover(){}
	
	Mover(ofVec3f _pos, float _mass);
	
	void applyForce(ofVec3f force);
	void applyDampingForce(float force);
	
	void update();
	void draw();

	
	ofVec3f pos, vel, acc;
	float mass, dist;
	
};


