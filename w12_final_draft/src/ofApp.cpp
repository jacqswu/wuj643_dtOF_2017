#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++) {
		balls.push_back(Ball());
	}
    
    vid.setup(640,480);

}

//--------------------------------------------------------------
void ofApp::update(){

   
	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
    
    vid.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
    
    ofSetColor(255);
    vid.draw(0,0,ofGetWidth(),ofGetHeight());
    
    
	// now, take a "screenshot" of the frame
    screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
	
	// resize the screenshot to 40x40 pixels
	
	screenImage.resize(20,20);
	
	
	// sample colors from the screenshot, and draw as a grid overlay:
	
	// overlay opacity based on mouse x
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
	
    ofSetColor(0, alpha);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());    // draw black rect to clear screen
	
	

	int nCols = 5;
	int nRows = 5;
	
	// grid square size for drawing:
	float width = ofGetWidth() / (float)nCols;
	float height = ofGetHeight() / (float)nRows;

	
	for (int y=0; y<nRows; y++) {
		for (int x=0; x<nCols; x++) {
			
			// sample the color of the screenshot at this grid pos
			ofColor color1 = screenImage.getColor(x*4+2,y*4+1);
			color1.a = alpha;
			ofSetColor(color1);
//            ofDrawRectangle(x * width, y * height, width, height);
            ofDrawTriangle(x * width, y * height, x * width + width, y * height, x * width + width/2, y * height + height/2);
            
            ofColor color2 = screenImage.getColor(x*4+3,y*4+2);
            color2.a = alpha;
            ofSetColor(color2);
            ofDrawTriangle(x * width + width, y * height, x * width + width, y * height + height, x * width + width/2, y * height + height/2);
            
            ofColor color3 = screenImage.getColor(x*4+2,y*4+3);
            color3.a = alpha;
            ofSetColor(color3);
            ofDrawTriangle(x * width + width/2, y * height + height/2, x * width + width, y * height + height, x * width, y * height + height);
            
            ofColor color4 = screenImage.getColor(x*4+1,y*4+2);
            color4.a = alpha;
            ofSetColor(color4);
            ofDrawTriangle(x * width, y * height, x * width + width/2, y * height + height/2, x * width, y * height + height);
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
