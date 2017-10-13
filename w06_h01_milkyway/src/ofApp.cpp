#include "ofApp.h"

// we declare these values as "globals" - they are outside of any class
//--------------------------------------------------------------

const int nMovers		= 600;
const int nAttractors	= 1;
// "const" means the values can never change (they are "hard-coded" here)


//--------------------------------------------------------------
// ofApp class definitions:
//--------------------------------------------------------------
void ofApp::setup(){
	
    background.load("images/background.jpg");
    backgroundalpha.load("images/background.png");
    halfdome.load("images/halfdome.png");
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
//    ofBackground(0,90);
	ofSetBackgroundAuto(false);
	ofSetFrameRate(30.);

	// construct Movers and Attractors
	
	// movers
	for (int m=0; m<nMovers; m++)
	{
		movers.push_back(Mover());
	}
	
	// attractors
    ofVec3f center;
    center.set( ofGetWidth() *.5, ofGetHeight() * .75 );    // center screen
    
    for (int a=0; a<nAttractors; a++)
    {
        Attractor attractor;
        attractor.pos = center;
//        attractor.pos.x += ofRandom(-250., 250.);    // keep attractors centered
//        attractor.pos.y += ofRandom(-250., 250.);    // within a 500x500 area

        attractors.push_back(attractor);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// apply attractors' gravity forces on movers
	for (int a=0; a<nAttractors; a++)
	{
		for (int m=0; m<nMovers; m++)
		{
			// calculate force
			ofVec3f force = attractors[a].getForce(movers[m]);
			// apply force
			movers[m].applyForce(force);
		}
	}
	
	// update movers
	for (int m=0; m<nMovers; m++)
	{
		movers[m].update();
        
        float rotRad = .005;
        
            ofVec2f center    = ofGetWindowSize()*.5;
            
            // rotate origPos of Mover
        
            
            // rotate pos of Mover
            
            ofVec2f vec        = movers[m].pos - center;
            float theta        = atan2(vec.y, vec.x) - rotRad;
            float radius    = vec.length();
            
            movers[m].pos.x = center.x + (cos(theta) * radius);
            movers[m].pos.y = center.y + (sin(theta) * radius);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
    
	// manually draw a semi-transparent background
    backgroundalpha.draw(0, 0, ofGetWidth(), ofGetHeight());
	// draw attractors and movers
	
//    for (int a=0; a<nAttractors; a++)
//    {
//        attractors[a].draw();
//    }
	
	for (int m=0; m<nMovers; m++)
	{
		movers[m].draw();
        halfdome.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
