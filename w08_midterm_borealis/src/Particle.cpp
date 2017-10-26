
#include "Particle.hpp"

Particle::Particle()
{
    //Initiate height of line
    length = 10.;
    width = 1.;
    xSize = 20;
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel)
{
	pos = _pos;
	vel = _vel;
}

void Particle::applyForce(ofVec3f force)
{
	acc += force;
}

void Particle::applyDamping(float strength)
{
	acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
    
    //Made height grow over time
    if(length < 350){
        length += 0.50;
        width += 0.01;
//        xSize += 0.01;
    }
    
    //Reset position if particle leaves screen
    if(pos.x < 0 || pos.x > ofGetWidth() || pos.y < 0 || pos.y > ofGetHeight()){
        pos.x = pos.x = ofRandom(ofGetWidth() * 0.4, ofGetWidth() * 0.6);
        pos.y = ofGetHeight() * 0.75;
        
        length = 10.;
        width = 1.;
    }
}

void Particle::draw(){
    
	ofPushStyle();
    
        //green
//        ofSetColor(104, 212, 65);
    
    
        //visual shape

//        ofDrawLine(pos.x,pos.y,pos.x,pos.y-length);
//        ofDrawRectangle(pos.x - width/2, pos.y - length, width, length);
    
    for(int x=0; x<xSize; x++){
        
        //Horizontal alpha gradient
        alpha2 = ofMap(x, 0, xSize, 3, 0);
    
        for(int i=0; i<length; i+=2){
            
            //Vertical color gradient
            saturation = ofMap(i, 0, length, 70., 255.);
            alpha = ofMap(i, 0, length, 80., 5.);
            color = ofColor::fromHsb(96, saturation, 220, alpha);
            
            //Main streak
            ofSetColor(color);
            ofDrawRectangle(pos.x - width/2, pos.y - i, width, 5);
            
            //Illuminating streaks
            ofSetColor(color, alpha2);
            
            ofDrawRectangle(pos.x - width/2 - width*x, pos.y - i, width, 5);
            ofDrawRectangle(pos.x - width/2 + width*x, pos.y - i, width, 5);

        }
    }
	
    ofPopStyle();
}

