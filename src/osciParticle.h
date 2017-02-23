#pragma once

#include "ofMain.h"

class osciParticle{
    
    public:
    
    osciParticle();
    
    void setup(int x, int y);
    void setPosition(int x, int y);
    void update();
    void draw();
    
    bool getIsAlive();
    ofVec2f getPosition();
    float getOpacity();
    
    ofVec2f position;
    float opacity;
    bool alive;
};