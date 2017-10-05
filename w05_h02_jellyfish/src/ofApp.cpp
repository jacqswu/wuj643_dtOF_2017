#include "ofApp.h"

//--------------------------------------------------------------
// Jelly class definitions:
//--------------------------------------------------------------

void Jelly::update(ofVec3f target){
	
	pos = pos * (1.-lerp) + target * lerp; // move "lerp" % to target
	
	
	ofVec3f direction = target - pos;
	
	float radians = atan2(direction.y, direction.x);	// atan2 returns angle in radians
	
	angle = ofRadToDeg(radians);	// convert radians to degrees
	

}

//--------------------------------------------------------------
void Jelly::draw(){
	
    
    ofPushMatrix();

	ofTranslate(pos);
    
    ofPushStyle();
    
    ofRotate(angle);

    //LEGS
    ofSetColor(255, 20);
    for(int i=-60; i<60; i+=15){
        ofDrawEllipse(-size, i, 5, 5);
    }
    
    //HEAD
    ofSetColor(color);
    ofDrawEllipse(0, 0, 50, size);
    
	ofPopStyle();

    ofPopMatrix();
	
}

//--------------------------------------------------------------
// end Jelly class definition
//--------------------------------------------------------------


//--------------------------------------------------------------
// ofApp definitions:
//--------------------------------------------------------------

void ofApp::setup(){
	
	ofBackground(0);
	
	int nObj = 100;
	
	for (int i=0; i<nObj; i++){
		
		Jelly obj;
		
		obj.pos = ofVec2f( 0 );
		
		obj.lerp = ofMap(i, 0, nObj, .01, .04);	// set interpolation "speed", slow to fast
		obj.size = ofMap(i, 0, nObj, 200, 100);		// set size, large to small
		
		float saturation = ofMap(i, 0, nObj, 50, 255);		// gradient
		obj.color = ofColor::fromHsb(220, saturation, 220, 70);	// hue, saturation, brightness
		
		objs.push_back(obj);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofVec3f target;
	target.set(ofGetMouseX(), ofGetMouseY());
	
	
	for (auto& obj : objs){		// alternative syntax for looping through vector
		
		obj.update(target);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (auto& obj : objs) {
		
		obj.draw();
		
		if (ofGetMousePressed()){
			ofSetColor(obj.color);
			ofDrawLine(obj.pos, ofVec2f(ofGetMouseX(), ofGetMouseY()));
		}
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
