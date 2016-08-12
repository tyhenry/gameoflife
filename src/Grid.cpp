//
//  Grid.cpp
//  gameOfLife
//
//  Created by Tyler on 8/11/16.
//
//

#include "Grid.hpp"


Grid::Grid(int w, int h): width(w), height(h){
    
    // grid size
    grid.resize(width);
    numSr.resize(width);
    for (int i=0; i<w; i++){
        grid[i].resize(height, false); // default to no life
        numSr[i].resize(height, 0); // start with no numSurround
    }
    bgColor = ofColor(10);
}

bool Grid::init(bool** life, int w, int h){
    
    // check dim overflow
    
    bool szGood = true;
    int endC = w;
    int endR = h;
    if (w > width) { szGood = false; endC = width; }
    if (h > height) { szGood = false; endR = height; }
    
    // init cells
    
    for (int c=0; c<endC; c++){
        for (int r=0; r<endR ; r++){
            
            grid[c][r] = life[c][r];
        }
    }
    
    start = true;
    
    return szGood;
    
}

bool Grid::initCell(int x, int y, bool alive){
    
    // check pos in grid
    
    bool posGood = x < width && y < height ? true: false;
    
    // init cell
    
    if (posGood) {
        grid[x][y] = alive;
    }
    
    start = true;
    
    return posGood;
}

void Grid::update(){
    
    if (!start) {
    
        // process next moves
        
        int nS = 0;
        
        for (int x = 0; x < width ; x++) {
            for (int y = 0; y < height ; y++) {
                
                nS = numSr[x][y]; // retrieve num cells surrounding cell
                
                // mutate
                
                if (nS < 2 || nS > 3) grid[x][y] = false;
                
                else if (nS == 2) grid[x][y] = grid[x][y];
                
                else if (nS == 3) grid[x][y] = true;
                
            }
        }
    }
    
    // get new num surrounding
    
    for (int x=0; x<width; x++){
        for (int y=0; y<height ; y++){
            
            numSr[x][y] = getNumSurroundCell(x,y);
        }
    }
    
    start = false;
    
}

bool Grid::getCell(int x, int y) {
    
    bool alive = false;
    
    if (x < width && y < height) {
        alive = grid[x][y];
    }
    
    return alive;
}

int Grid::getNumSurroundCell(int x, int y) {
    
    if (x<0 || x>=width || y<0 || y>=width) return 0;
    
    int nS = 0;
    
    // edge check
    
    bool left = x-1 < 0;
    bool right = x+1 >= width;
    bool top = y-1 < 0;
    bool bottom = y+1 >= height;
    
    // get num surrounding
    
    if (!left){
        nS += grid[x-1][y];                 // left
        if (!top) nS += grid[x-1][y-1];     // top-left
        if (!bottom) nS += grid[x-1][y+1];  // bottom-left
    }
    
    if (!right){
        nS += grid[x+1][y];                 // right
        if (!top) nS += grid[x+1][y-1];     // top-right
        if (!bottom) nS += grid[x+1][y+1];  // bottom-right
    }
    
    if (!top) nS += grid[x][y-1];           // top
    if (!bottom) nS += grid[x][y+1];        // bottom
    
    return nS;
}

void Grid::setColors(ofColor clrs[9]){
    
    for (int i=0; i<9; i++){
        colors[i] = clrs[i];
    }
}

void Grid::draw(int cellSize, float posX, float posY) {
    
    ofPushMatrix();
    ofTranslate(posX,posY);
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(0,0,width*cellSize,height*cellSize); // bg

    for (int x=0; x<width; x++){
        for (int y=0; y<height; y++){
            
            if (grid[x][y]){ // only draw life
                
                ofSetColor(colors[numSr[x][y]]); // color for num surrounding
                ofDrawRectangle(x*cellSize, y*cellSize, cellSize, cellSize);
            }
        }
    }
    ofPopStyle();
    ofPopMatrix();
}



