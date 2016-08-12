#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(120);
    
    // gui
    
    gui = new ofxDatGui(0,0);
    gui->setTheme(new GuiTheme);
    
    fpsSlider = gui->addSlider("fps",0,60);
    fpsSlider->setPrecision(0); // int
    fpsSlider->setValue(60);
    fpsSlider->onSliderEvent([&](ofxDatGuiSliderEvent e){
        frameWaitSec = 1.f/e.target->getValue();
    });
    
    widthSlider = gui->addSlider("grid width", 0, ofGetWidth()-gui->getWidth());
    widthSlider->setPrecision(0); // int
    widthSlider->setValue(200);
    
    heightSlider = gui->addSlider("grid height", 0, ofGetHeight());
    heightSlider->setPrecision(0); // int
    heightSlider->setValue(200);
    
    lifeSlider = gui->addSlider("pct start alive", 0, 100);
    lifeSlider->setPrecision(0);
    lifeSlider->setValue(50);
    
    restartBtn = gui->addButton("(re-)start");
    restartBtn->onButtonEvent([&](ofxDatGuiButtonEvent e){
        float pctAlive = lifeSlider->getValue()/100.f;
        restart(widthSlider->getValue(), heightSlider->getValue(), pctAlive);
    });
    
    cellSzSlider = gui->addSlider("cell size (px)", 1, 100);
    cellSzSlider->setPrecision(0); // int
    int cellSz = ofGetHeight()/heightSlider->getValue();
    cellSzSlider->setValue(cellSz);
    
    gui->update();
    
    
    // start

    float pctAlive = lifeSlider->getValue()/100.f;
    restart(widthSlider->getValue(), heightSlider->getValue(), pctAlive);
    
    gamePos = ofVec2f(gui->getPosition().x+gui->getWidth()+10,0);
    ofColor colors[9] = {ofColor::white};
    for (int i=0;i<9;i++){
        int hue = ofMap(i,0,9,110,255);
        colors[i] = ofColor::fromHsb(hue,255,255);
    }
    grid.setColors(colors);
    
    frameWaitSec = 1.f/60.f;
    lastFrameTime = ofGetElapsedTimef();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetElapsedTimef() - lastFrameTime > frameWaitSec) {
        grid.update();
        lastFrameTime = ofGetElapsedTimef();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grid.draw(cellSzSlider->getValue(), gamePos.x, gamePos.y);

}

void ofApp::restart(int width, int height, float pctAlive){
    
    grid = Grid(width,height);
    
    for (int x=0; x<width; x++){
        for (int y=0; y<height; y++){
            
            if (ofRandom(0.0,1.0) <= pctAlive){
                grid.initCell(x,y);
            }
        }
    }
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
