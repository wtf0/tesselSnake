#include "osciParticle.h"

osciParticle::osciParticle(){
    
}

void osciParticle::setup(int x, int y){
    
    
    position.x = x;
    position.y = y;
    opacity = 255;
    alive = true;
    
}

void osciParticle::setPosition(int x, int y){
    
    position.x = x;
    position.y = y;
    
}

void osciParticle::update(){
    
    opacity -= 1;
    if(opacity <= 0){
        alive = false;
    }
    
    
}

void osciParticle::draw(){
    
    ofSetColor(255,255,255, opacity);
    ofDrawRectangle(position, 5,5);
    
}

bool osciParticle::getIsAlive(){
    
    return alive;
    
}

ofVec2f osciParticle::getPosition(){
    
    return position;
    
}
float osciParticle::getOpacity(){
    
    return opacity;
    
}