#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    
    
    gravity = ofVec2f(0,0); // start with no gravity force
    wind = ofVec2f(0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // wind force (x) pushes balls off cliff, where gravity (y) kicks in
    wind.x = 0.15;
    gravity.y = 0.98;
    
    ball1.update(wind);
    ball2.update(wind);
    ball3.update(wind);

    if(ball1.pos.x>300){
//        wind.x = 0;
        ball1.update(gravity); // apply gravity to balls
    }
    if(ball2.pos.x>300){
//        wind.x = 0;
        ball2.update(gravity);
    }
    if(ball3.pos.x>300){
//        wind.x = 0;
        ball3.update(gravity);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    ofDrawRectangle(0, 200, 300, ofGetWindowHeight()-200);
    

	ball1.draw();
	ball2.draw();
	ball3.draw();

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
