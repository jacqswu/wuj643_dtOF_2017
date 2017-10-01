#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    
    //HAIR LEFT
    ofSetColor(0);
    ofPushMatrix();
        ofTranslate(63, 145);
        ofRotate(ofMap(ofGetMouseX(), ofGetWidth(), 0, 45, 135));
        ofDrawRectangle(0, 0, 49, 162);
    ofPopMatrix();
    
    //HEAD SHAPE
    ofSetColor(255, 232, 208);
    ofDrawEllipse(146, 176, 138, 184);
    
    //EYES
    ofPath eyes;
    eyes.setColor(0);
    //    path.moveTo(300 + 200, 300);
    eyes.arc(115, 182, 12, 12, 0, 180);
    eyes.arc(164, 182, 12, 12, 0, 180);
    //    path.setFilled(false);
    //    path.setStrokeWidth(2);
    eyes.draw();
    eyes.close();
    
    //MOUTH
    ofPath mouth;
    mouth.setColor(ofColor(241, 102, 107));
    mouth.triangle(127, 232, 134, 219, 140, 232);
    mouth.triangle(140, 232, 147, 219, 153, 232);
    mouth.triangle(127, 232, 140, 244, 153, 232);
    mouth.draw();
    mouth.close();
    
    //HAIR RIGHT
    ofSetColor(0);
    ofPushMatrix();
        ofTranslate(189, 145);
        ofRotate(ofMap(ofGetMouseX(), ofGetWidth(), 0, 45, 135));
         ofDrawRectangle(0, 0, 37, 162);
        ofPopMatrix();
   
    
    //BANGS
    ofPushMatrix();
        ofTranslate(135, 63);
        ofRotate(45);
        ofDrawRectangle(0, 0, 50, 136);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(132, 96);
        ofRotate(-45);
        ofDrawRectangle(0, 0, 48, 112);
    ofPopMatrix();
    
    
    
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
