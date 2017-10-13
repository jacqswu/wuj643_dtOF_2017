//
//  Attractor.cpp
//  Attractors
//
//  Created by Tyler on 10/6/17.
//  Modified by Jacqueline on 10/12/17.
//

#include "Attractor.hpp"

Attractor::Attractor()
{
    pos.x = ofGetWidth()*0.5;
    pos.y = ofGetHeight()*0.75;
	mass = ofRandom(30.);
	
}

Attractor::Attractor(ofVec3f _pos, float _mass)
{
	pos = _pos;
//    mass = ofClamp(_mass, 5., 30.); // keep mass between 10 and 30
	
}

ofVec3f Attractor::getForce(Mover mover)
{
	// calculate a force of attraction on mover
	
	ofVec3f dir		= pos - mover.pos;	// the target is the attractor
	float distance	= dir.length();
 
	// we'll model gravity:
	// from http://natureofcode.com/book/chapter-2-forces/#chapter02_section9
	//
	// gravity magnitude = (G * mass1 * mass2) / (distance * distance)
	//
	//		where G = gravitational constant
	
	// we'll "clamp" the distance between 5 and 25
	// to prevent super-massive or super-micro gravity forces
	// ... this is a hack to keep things in equilibrium!
	distance			= ofClamp(distance, 5., 25.);
	
	float strength	= (G * mass * mover.mass) / (distance * distance);
	
	ofVec3f force	= dir.getNormalized() * strength;
	
	return force;
}

void Attractor::draw()
{
	ofPushStyle();

	
	// radius based on mass
//    ofDrawCircle(pos, mass);

	ofPopStyle();
}
	
	
	
	
