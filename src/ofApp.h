#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "Grid.hpp"

class GuiTheme : public ofxDatGuiTheme {
public:
    
    GuiTheme(int width = 400) {
        font.size = 8;
        layout.width = width;
        layout.labelWidth = 100;
        layout.upperCaseLabels = false;
        layout.breakHeight = 10.0f;
        init();
    }
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void restart(int height, int width, float pctAlive);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Grid grid;
    float lastFrameTime = 0;
    
    ofxDatGui* gui;
    ofxDatGuiSlider* fpsSlider;
    ofxDatGuiSlider* widthSlider;
    ofxDatGuiSlider* heightSlider;
    ofxDatGuiSlider* lifeSlider;
    ofxDatGuiButton* restartBtn;
    ofxDatGuiSlider* cellSzSlider;
    
    float frameWaitSec = 0;
    ofVec2f gamePos;
    
		
};
