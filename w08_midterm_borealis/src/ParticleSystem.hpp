//
//  ParticleSystem.hpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
	
	ParticleSystem(){}
	~ParticleSystem(){}
    
    vector<Particle> particles;
	
	void update();
	void draw();
	
    int xSize;
    
    float alpha2;
	
};
