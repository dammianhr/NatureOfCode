//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "mover.h"

void mover::setup(float m, float x, float y){
    mass = m;
    location.set(x,y);
    velocity.set(0,0);
    acceleration.set(0,0);
}

void mover::applyForce(ofPoint force){
    ofPoint f;
    f = force/mass;
    acceleration += f;
}

void mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void mover::display(){

    ofSetColor(0,127);
    ofFill();
    ofCircle(location.x, location.y, mass*8);
    
    ofSetColor(0);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(location.x, location.y, mass*8);

}

void mover::checkEdges(){
    if (location.y > ofGetHeight()) {
        velocity.y *= -0.9;
        location.y = ofGetHeight();
    }
}