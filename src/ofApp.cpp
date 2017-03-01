#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    tailOne.setup();


}

//--------------------------------------------------------------
void ofApp::update(){
    
    tailOne.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

    tailOne.draw();
    
    ofSetColor(255,255,255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == '1'){
        tailOne.setDrawMode(1);
    }
    
    if(key == '2'){
        tailOne.setDrawMode(2);
    }
    if(key == '3'){
        tailOne.setDrawMode(3);
    }
    if(key == '0'){
        tailOne.setDrawMode(0);
    }
    if(key == 'c'){
        
        ofToggleFullscreen();
        
    }

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
