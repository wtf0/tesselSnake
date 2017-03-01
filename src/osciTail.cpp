

#include "osciTail.h"

osciTail::osciTail(){
    
    
    
}
//------------------------------------------
void osciTail::setup(){
    
    numSteps = 30;
    distThresh = 3;
    tessellation.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    drawSetting = 0;
    
}
//------------------------------------------
void osciTail::addPoint(ofVec2f currentPos){
    
    //only insert point if distance is enough
    
    if(tail.size() > 0){
        ofVec2f current;
        current.x = currentPos.x;
        current.y = currentPos.y;
        
        ofVec2f next;
        int end = tail.size()-1;
        next.x = tail[end].getPosition().x;
        next.y = tail[end].getPosition().y;
        
        float distance = ofDist(current.x, current.y, next.x, next.y);
        cout << distance << endl;
        if(distance > distThresh){
            osciParticle tmpPart;
            tmpPart.setup(currentPos.x, currentPos.y);
            tail.push_back(tmpPart);
            cout << "point added" << endl;
        }
    }else{
        osciParticle tmpPart;
        tmpPart.setup(currentPos.x, currentPos.y);
        tail.push_back(tmpPart);
    }
}
//------------------------------------------
void osciTail::setDrawMode(int mode){
    
    drawSetting = mode;
    
}

//------------------------------------------
void osciTail::update(){
    vector <int> killThem;
    for(int i = 0; i < tail.size(); i++){
        tail[i].update();
        if(tail[i].getIsAlive() == false){
            killThem.push_back(i);
        }
    }
    for(int j = 0; j < killThem.size(); j++){
        tail.erase(tail.begin()+ killThem[j]);
    }
    killThem.clear();
}
//------------------------------------------
void osciTail::draw(){
    
    
    if(tail.size() > 0){
        
        
        std::reverse(bottomPoints.begin(),bottomPoints.end());
        
        line.addVertices(topPoints);
        line.addVertices(bottomPoints);
        line.close();
        line=line.getSmoothed(3);
        vector <ofPoint> holder = line.getVertices();
        
        
        for(int l = 0; l < holder.size(); l ++){
            
            path.curveTo(holder[l]);
            
        }
        
        if(drawSetting == 1){
            tessellation = path.getTessellation();
        }
    
        ofColor greenish;
        greenish.set(153, 255,182, 255);
        path.setColor(greenish);
        
        
        holder = line.getVertices();
        for(int l = 0; l < holder.size(); l ++){
            pathTwo.curveTo(holder[l]);
            
        }
        line.clear();
        
        
        if(drawSetting == 3){
            //ofColor greenish;
            greenish.set(153, 255,182, 255);
            path.setColor(greenish);
            path.setStrokeWidth(4);
            path.draw();
            path.clear();
            
            ofColor light;
            light.set(234, 255,241, 255);
            pathTwo.setColor(light);
            pathTwo.setStrokeWidth(2);
            pathTwo.draw();
            pathTwo.clear();
        }
        
        path.clear();
        pathTwo.clear();
        
        topPoints.clear();
        bottomPoints.clear();
        
        topPointsTwo.clear();
        bottomPointsTwo.clear();
        
        topPointsThree.clear();
        bottomPointsThree.clear();
        
        angles.resize(tail.size());
        for(int j = 0; j < tail.size() -1; j++){
            
            ofVec2f current;
            current.x = tail[j].getPosition().x;
            current.y = tail[j].getPosition().y;
            
            ofVec2f next;
            next.x = tail[j+1].getPosition().x;
            next.y = tail[j+1].getPosition().y;
            
            float distance = ofDist(current.x, current.y, next.x, next.y);
            float distX = current.x - next.x;
            float distY = current.y - next.y;
            float stepX = distX / numSteps;
            float stepY = distY / numSteps;
            
            if(numSteps != 0){
                stepSize = distance / numSteps;
            }
            
            ofVec2f frc = current - next;
            frc.normalize();
            
            ofVec2f delta;
            delta.x = (current.x + frc.x) - current.x;
            delta.y = (current.y + frc.y) - current.y;
            
            angles[j] = atan2(delta.y, delta.x) * RAD_TO_DEG;
            
            ofPoint atNinety;
            
            float width = (ofNoise(ofRandom(0, 2)))*6;
            
            float tmpAngle = 90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            topPoints.push_back(atNinety);
          
            tmpAngle = -90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            bottomPoints.push_back(atNinety);
            
            width = (ofNoise(ofRandom(0, 2)))*2;
            
            tmpAngle = 90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            topPointsTwo.push_back(atNinety);
            
            ofSetColor(255,255,255);
            //ofDrawRectangle(atNinety.x, atNinety.y, 5, 5);
            
            tmpAngle = -90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            bottomPointsTwo.push_back(atNinety);
            
            width = (ofNoise(ofRandom(0, 2)))*10;
            
            tmpAngle = 90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            topPointsThree.push_back(atNinety);
            if(drawSetting == 2){
                ofDrawRectangle(atNinety.x, atNinety.y, 5, 5);
            }
            tmpAngle = -90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            bottomPointsThree.push_back(atNinety);

            if(drawSetting == 2){
                ofSetColor(255,255,255);
                ofDrawRectangle(atNinety.x, atNinety.y, 5, 5);
                ofPushMatrix();
                    ofTranslate(tail[j].getPosition().x, tail[j].getPosition().y);
                    if(j == 0){
                    ofDrawBitmapString("this is patient 0", 5, 5);
                    }
                    ofRotate(angles[j], 0, 0, 1);
                    ofSetColor(255, 0, 0, 190);
                    ofDrawLine(0, 0, -10, 0);
                    //ofDrawRectangle(0, 0, 5, 30);
                ofPopMatrix();
            }
        }
        if(topPoints.size() > 1){
            if(drawSetting == 0){
                for(int i = 0; i < topPoints.size(); i++){
                    tessellation.addVertex(topPointsThree[i]);
                    tessellation.addVertex(bottomPointsThree[i]);
                }
                for(int j = 0; j < tessellation.getNumVertices() - 3; j++){
                    
                    ofColor colour;
                    int arrayPos = ofMap(j, 0, tessellation.getNumVertices(), 0, tail.size());
                    colour.set(153, 255,182, tail[arrayPos].getOpacity());
                    tessellation.addColor(colour);
                    tessellation.addIndex(j);
                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+3);
                    
                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+2);
                    tessellation.addIndex(j+3);
                }
                    tessellation.drawWireframe();
                    tessellation.clear();
                
                for(int i = 0; i < topPoints.size(); i++){
                    tessellation.addVertex(topPoints[i]);
                    tessellation.addVertex(bottomPoints[i]);
                }
                for(int j = 0; j < tessellation.getNumVertices() - 3; j++){
                    
                    ofColor colour;
                    int arrayPos = ofMap(j, 0, tessellation.getNumVertices(), 0, tail.size());
                    colour.set(0, 255,0, tail[arrayPos].getOpacity());
                    tessellation.addColor(colour);
                    tessellation.addIndex(j);
                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+3);

                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+2);
                    tessellation.addIndex(j+3);
                }
                tessellation.drawWireframe();
                tessellation.clear();
                
                for(int i = 0; i < topPoints.size(); i++){
                    tessellation.addVertex(topPointsTwo[i]) ;
                    tessellation.addVertex(bottomPointsTwo[i]);
                }
                for(int j = 0; j < tessellation.getNumVertices() - 3; j++){
                    
                    ofColor colour;
                    int arrayPos = ofMap(j, 0, tessellation.getNumVertices(), 0, tail.size());
                    colour.set(234, 255,241, tail[arrayPos].getOpacity());
                    tessellation.addColor(colour);
                    
                    tessellation.addIndex(j);
                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+3);
                    
                    tessellation.addIndex(j+1);
                    tessellation.addIndex(j+2);
                    tessellation.addIndex(j+3);
                }
                tessellation.drawWireframe();
            }
        }
        
    }
    if(drawSetting == 1){
        tessellation.drawWireframe();
    }
    tessellation.clear();

}