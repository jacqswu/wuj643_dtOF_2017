#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(true);
    mainOutputSyphonServer.setName("Screen Output");
    
    vid.listDevices();
    vid.setDeviceID(1);
    
    // setup webcam
    vid.setup(640,480);
    
    // allocate the fbo memory
    fbo.allocate(640,480,GL_RGBA);
    
    // clear the fbo's pixels (removes junk data):
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    fboTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vid.update();

    fbo.begin();
        ofClear(255,255,255, 0);
        ofSetColor(255);
        vid.draw(0,0,640,480);
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    http://openframeworks.cc/documentation/graphics/ofPixels/
    
    ofSetColor(255);
    fbo.draw(-319,0, 1366,1024);
    
    // now, take a "screenshot" of the frame
    screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
//        screenImage.mirror(false,true);
    
    //    fbo.readToPixels(screenImage);
    
    // resize the screenshot
    screenImage.resize(20,20);
    screenImage.update();
    
    //    screenImage.draw(0,0, ofGetWidth(), ofGetHeight());
    
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
    
    
    //MATH FOR RECTANGLES
    /*
     for (int y=0; y<nRows; y++) {
     for (int x=0; x<nCols; x++) {
     
     // sample the color of the screenshot at this grid pos
     ofColor color = screenImage.getColor(x,y);
     //            color.a = alpha;
     //            cout << color << endl;
     
     // TESTING WITH RECTANGLES FIRST. THIS PART DOESN'T WORK
     ofSetColor(color);
     ofDrawRectangle(x * width, y * height, width, height);
     }
     }
     
     */
    
    
    //MATH FOR MOSAIC
    
    for (int y=0; y<nRows; y++) {
        for (int x=0; x<nCols; x++) {
            
            // sample the color of the screenshot at this grid pos
            ofColor color1 = screenImage.getColor(x*4+2,y*4+1);
            color1.a = alpha;
            //            color1.setSaturation(0);
            //            color1.invert();
            ofSetColor(color1);
            ofDrawTriangle(x * width, y * height, x * width + width, y * height, x * width + width/2, y * height + height/2);
            
            ofColor color2 = screenImage.getColor(x*4+3,y*4+2);
            color2.a = alpha;
            //            color2.setSaturation(0);
            //            color2.invert();
            ofSetColor(color2);
            ofDrawTriangle(x * width + width, y * height, x * width + width, y * height + height, x * width + width/2, y * height + height/2);
            
            ofColor color3 = screenImage.getColor(x*4+2,y*4+3);
            color3.a = alpha;
            //            color3.setSaturation(0);
            //            color3.invert();
            ofSetColor(color3);
            ofDrawTriangle(x * width + width/2, y * height + height/2, x * width + width, y * height + height, x * width, y * height + height);
            
            ofColor color4 = screenImage.getColor(x*4+1,y*4+2);
            color4.a = alpha;
            //            color4.setSaturation(0);
            //            color4.invert();
            ofSetColor(color4);
            ofDrawTriangle(x * width, y * height, x * width + width/2, y * height + height/2, x * width, y * height + height);
        }
    }
    
    mainOutputSyphonServer.publishScreen();
    
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

