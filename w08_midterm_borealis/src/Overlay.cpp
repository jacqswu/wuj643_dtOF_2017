//
//  Overlay.cpp
//  w08_midterm_borealis
//
//  Created by Jacqueline Wu on 10/22/17.
//

#include "Overlay.hpp"

Overlay::Overlay()
{
}

void Overlay::draw(){

    ofSetColor(0,10);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());

}

