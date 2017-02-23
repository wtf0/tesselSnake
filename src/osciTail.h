#pragma once

#include "osciParticle.h"
#include "ofMain.h"

class osciTail{
    
    public:
    
    osciTail();
    
    void setup();
    void addPoint(ofVec2f currentPos);
    void update();
    void draw();

    
    int stepSize;
    
    vector <osciParticle> tail;
    vector <float> angles;
    vector <ofPoint> topPoints;
    vector <ofPoint> bottomPoints;
    vector <ofPoint> topPointsTwo;
    vector <ofPoint> bottomPointsTwo;

    
    ofPolyline line;
    ofPath path;
    ofPath pathTwo;
    
    int numSteps;
    int distThresh;
    ofVboMesh tessellation;
    
};