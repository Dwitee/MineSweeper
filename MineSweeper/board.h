//
//  board.h
//  MineSweeper
//
//  Created by DwiteeKP on 07/05/15.
//  Copyright (c) 2015 DwiteeKP. All rights reserved.
//

#ifndef MineSweeper_board_h
#define MineSweeper_board_h

class Board
{
public:
    Board(unsigned int mines,unsigned int sizex,unsigned int sizey);
    ~Board();
    void GenerateMineField(unsigned int width, unsigned int height, unsigned int count);
    void printAnswer();
    void printUI();
    char getData(int x, int y);
    void moveToUIF(int x, int y);
    void checkEmptyField(int x, int y);
    int addToMinecount(int x, int y, int& minecount);
    int getGameStatus();
private:
    // multidimensional board arrays
    //what the user sees
    char** uif;
    //what there actually is
    char** data;
    //size of arrays (and board)
    const int sizeX;
    const int sizeY;
};

#endif
