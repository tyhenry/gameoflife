//
//  Grid.hpp
//  gameOfLife
//
//  Created by Tyler on 8/11/16.
//
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "ofMain.h"

class Grid {
    
public:
    
    Grid(int w=1000, int h=1000); // default 1000x1000
    
    bool init(bool** life, int w, int h); // init, returns false if array is bigger than grid
    bool initCell(int x, int y, bool alive=true); // init a single cell, returns false if outside grid
    
    void update(); // generate mutations
    
    bool getCell(int x, int y);
    int getNumSurroundCell(int x, int y);
    int getWidth() { return width; }
    int getHeight() { return height; }
    
    void setColors(ofColor clrs[9]); //0-9 surrounding num -> color
    void setBgColor(ofColor c) { bgColor = c; }
    
    void draw(int cellSize, float posX=0, float posY=0); // at (x,y), width*cellSize x height*cellSize
    void draw(float x, float y, float w, float h);
    void draw(ofVec2f pos, int w, int h) { draw(pos.x,pos.y,w,h); }
    
private:
    
    int width, height;
    vector <vector <bool>> grid; // <x <y>>
    vector <vector <int>> numSr; // num surrounding
    ofColor colors[9] = {ofColor::white};
    ofColor bgColor;
    
    bool start = true;
    
};

#endif /* Grid_hpp */
