

#include "osciTail.h"

osciTail::osciTail(){
    
    
    
}
//------------------------------------------
void osciTail::setup(){
    
    numSteps = 10;
    distThresh = 7;
    tessellation.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
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
        /*
        std::reverse(bottomPoints.begin(),bottomPoints.end());
        
        line.addVertices(topPoints);
        line.addVertices(bottomPoints);
        line.close();
        line=line.getSmoothed(3);
        vector <ofPoint> holder = line.getVertices();
        
        
        for(int l = 0; l < holder.size(); l ++){
            
            path.curveTo(holder[l]);
            
        }
        //tessellation = path.getTessellation();
        
        ofColor greenish;
        greenish.set(153, 255,182, 255);
        path.setColor(greenish);
        
        
        holder = line.getVertices();
        for(int l = 0; l < holder.size(); l ++){
            pathTwo.curveTo(holder[l]);
            
        }
        line.clear();
        
        //ofColor greenish;
        greenish.set(153, 255,182, 255);
        path.setColor(greenish);
        path.setStrokeWidth(4);
        //path.draw();
        path.clear();
        
        ofColor light;
        light.set(234, 255,241, 255);
        pathTwo.setColor(light);
        pathTwo.setStrokeWidth(2);
        //pathTwo.draw();
        pathTwo.clear();
        */
        
        std::reverse(bottomPoints.begin(),bottomPoints.end());
        std::reverse(topPoints.begin(),topPoints.end());

        for(int i = 0; i < topPoints.size()-1; i++){
            
            ofColor colour;
            tessellation.addVertex(topPoints[i]);
            colour.set(255, 255, 255);//, tail[tail.size()-i].getOpacity());
            tessellation.addColor(colour);
            tessellation.addIndex(i);   //a
            tessellation.addIndex(i+1);//b
            tessellation.addIndex(i+3);//d
            
            tessellation.addIndex(i + 1);   //b
            tessellation.addIndex(i+2);//c
            tessellation.addIndex(i+3);//d
            
            tessellation.addVertex(bottomPoints[i]);
            colour.set(255, 255, 255);//, tail[tail.size()-i].getOpacity());
            tessellation.addColor(colour);
            tessellation.addIndex(i+1);   //a
            tessellation.addIndex(i+2);//b
            tessellation.addIndex(i+4);//d
            
            tessellation.addIndex(i + 2);   //b
            tessellation.addIndex(i+3);//c
            tessellation.addIndex(i+4);//d
            
        }
        
        
        topPoints.clear();
        bottomPoints.clear();
        
        topPointsTwo.clear();
        bottomPointsTwo.clear();
        
        angles.resize(tail.size());
        for(int j = 0; j < tail.size() -1; j++){
            /*
             ofSetColor(0,255,0, 127);
             ofSetLineWidth(5);
             ofDrawLine(tail[j].getPosition(), tail[j+1].getPosition());
             ofSetColor(255, 255, 255, 200);
             ofSetLineWidth(2);
             ofDrawLine(tail[j].getPosition(), tail[j+1].getPosition());
             */
            
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
          
            /*
            ofColor colour;
            tessellation.addVertex(atNinety);
            tessellation.addIndex(j);
            tessellation.addIndex(j+1);
            tessellation.addIndex(j+2);
            tessellation.addIndex(j);
            colour.set(255, 255, 255, tail[j].getOpacity());
            tessellation.addColor(colour);
             */
            ofSetColor(255,0,0);
            ofDrawRectangle(atNinety.x, atNinety.y, 5, 5);
            
            tmpAngle = -90 + angles[j];
            atNinety.x = current.x + width * (cos(tmpAngle*PI/180));
            atNinety.y = current.y + width * (sin(tmpAngle*PI/180));
            bottomPoints.push_back(atNinety);
            /*
            tessellation.addVertex(atNinety);
            tessellation.addIndex(j);
            tessellation.addIndex(j+1);
            tessellation.addIndex(j+2);
            colour.set(255, 255, 255, tail[j].getOpacity());
            tessellation.addColor(colour);
            */


            
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
            /*
            for(int i = 0; i < topPoints.size()-1; i++){
                
                tessellation.addVertex(topPoints[i]);
                tessellation.addVertex(bottomPoints[i]);
                tessellation.addVertex(topPoints[i+1]);
                tessellation.addIndex(i);
                tessellation.addIndex(i+1);
                tessellation.addIndex(i+2);
                tessellation.addVertex(bottomPoints[i+1]);
                tessellation.addVertex(topPoints[i]);
                tessellation.addVertex(bottomPoints[i]);
                tessellation.addIndex(i);
                tessellation.addIndex(i+1);
                tessellation.addIndex(i+2);
                
            }
            */
            
            //ofDrawRectangle(atNinety.x, atNinety.y, 5, 5);
            
             ofPushMatrix();
                 ofTranslate(tail[j].getPosition().x, tail[j].getPosition().y);
            if(j == 0){
                ofDrawBitmapString("this is patient 0", 5, 5);
            }
                 ofRotate(angles[j], 0, 0, 1);
                 ofSetColor(255,255,255);
                 ofDrawLine(0, 0, -10, 0);
                 ofSetColor(255, 0, 0, 50);
                 ofDrawRectangle(0, 0, 5, 30);
             ofPopMatrix();
        }
    }
    tessellation.drawWireframe();
    tessellation.clear();

}