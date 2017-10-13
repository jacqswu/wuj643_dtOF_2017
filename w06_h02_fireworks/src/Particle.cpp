//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//  Edited by Jacqueline on 10/12/17.
//

#include "Particle.hpp"

Particle::Particle()
{
	lifespan = 2.; // seconds
}

Particle::Particle(ofVec3f _pos)
{
	pos = _pos;
	vel.x = ofRandom(-5, 5);
	vel.y = ofRandom(-5, 5);
	lifespan = 2.;
}

void Particle::applyForce(ofVec3f force){
	acc += force;
}

void Particle::update(float timeDiff){ // how much time has passed since last frame?
	vel += acc;
	pos += vel;
	acc *= 0;
	
	lifespan -= timeDiff;
	if (lifespan < 0.) lifespan = 0.;
}

void Particle::draw(){
	ofPushStyle();
	float hue = ofMap(lifespan, 0., 3., 0, 255);
	ofSetColor(ofColor::fromHsb(hue,hue,255));
	
	ofDrawCircle(pos, 2);
	ofPopStyle();
}

