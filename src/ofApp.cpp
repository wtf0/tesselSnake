#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofBackground(17,50, 48);
    
    tailOne.setup();


}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    float left = 10;
    float down = 10;
    
    left ++;
    
    ofVec2f tmp;
    tmp.x = left;
    tmp.y = down;
   // tailOne.addPoint(tmp);


    tailOne.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    tailOne.draw();
    
    ofSetColor(255,255,255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofVec2f mouse;
    mouse.x = x;
    mouse.y = y;
    
    tailOne.addPoint(mouse);
    
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
