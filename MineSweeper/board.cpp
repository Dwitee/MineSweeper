//
//  board.cpp
//  MineSweeper
//
//  Created by DwiteeKP on 07/05/15.
//  Copyright (c) 2015 DwiteeKP. All rights reserved.
//

#include "board.h"
#include <iostream>
#include <time.h>
#include <cstdlib>


using namespace std;


//ctor
Board::Board(unsigned int mines, unsigned int sizex,  unsigned int sizey) : sizeX(sizex), sizeY(sizey)
{
    //srand(time(NULL));
    // init arrays
    uif = new char* [sizeX];
    data = new char* [sizeX];
    for(int i = 0; i < sizeX; i++){
        uif[i] = new char[sizeY];
        data[i] = new char[sizeY];
    }
    
    // fill arrays with dots
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            uif[x][y] = '.';
            data[x][y] = '.';
        }
    }
    
    //add mines to data, not uif
    for(int i = 0; i < mines; i++)
    {
        int x, y;
        while(true)
        {
            x = rand() % sizeX;
            y = rand() % sizeY;
            if(data[x][y] != 'm')
            {
                data[x][y] = 'm';
                break;
            }
        }
    }
    
    //add numbers to data, not uif
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            if(data[x][y] != 'm')
            {
                int minecount = 0;
                addToMinecount(x - 1, y - 1, minecount);
                addToMinecount(x, y - 1, minecount);
                addToMinecount(x + 1, y - 1, minecount);
                addToMinecount(x - 1, y, minecount);
                addToMinecount(x + 1, y, minecount);
                addToMinecount(x - 1, y + 1, minecount);
                addToMinecount(x, y + 1, minecount);
                addToMinecount(x + 1, y + 1, minecount);
                char c = (char)(((int)'0')+minecount);
                data[x][y] = c;
            }
        }
    }
}

Board::~Board()
{
    // delete inner arrays
    for(int i = 0; i < sizeY; i++)
    {
        delete[] data[i];
        delete[] uif[i];
    }
    // delete outer arrays
    delete[] data;
    delete[] uif;
}

void Board::GenerateMineField(unsigned int width, unsigned int height, unsigned int count)
{
    char** value;
    value = new char* [width];
    for(int i = 0; i < width; i++){
        value[i] = new char[height];
    }
    
    // fill arrays with dots
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            value[x][y] = '.';
        }
    }
    
    //add mines to value using rand()
    for(int i = 0; i < count; i++)
    {
        int x, y;
        while(true)
        {
            x = rand() % width;
            y = rand() % height;
            if(value[x][y] != 'M')
            {
                value[x][y] = 'M';
                break;
            }
        }
    }
    
    int a,b;
    
    //add numbers to data for all the eight neighbour
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(value[x][y] != 'M')
            {
                int minecount = 0;
                
                //top left
                a = x-1;
                b = y-1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
               
                //top mid
                a = x;
                b = y-1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                // top right
                a = x+1;
                b = y-1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                // left mid
                a = x-1;
                b = y;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                //right mid
                a = x+1;
                b = y;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                //left bottom
                a = x-1;
                b = y+1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                //bottom mid
                a = x;
                b = y+1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                //bottom right
                a = x+1;
                b = y+1;
                if(a >= 0 && a < sizeX && b >= 0 && b < sizeY)
                {
                    if(value[a][b] == 'M') minecount++;
                }
                char c = (char)(((int)'0')+minecount);
                if ( minecount > 0)
                    value[x][y] = c;
            }
        }
    }
    
    //print the arrays
    // newline and 3 spaces
 
    
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            cout << value[x][y];
        }
        cout << endl;
    }
    cout << endl;
    
    
    //delete array after use
    
    // delete inner arrays
    for(int i = 0; i < sizeY; i++)
    {
        delete[] value[i];
    }
    // delete outer arrays
    delete[] value;
   
}

//print board
void Board::printAnswer()
{
    // newline and 3 spaces
    cout << endl << "   ";
    
    //print abcde... etc
    for(int i = 0; i < sizeX; i++)
    {
        cout << (char) (97 + i);
    }
    cout << endl << endl;
    
    for(int y = 0; y < sizeY; y++)
    {
        // a is nr 97 on ascii table, 97 + 1 to char = b
        cout << (char) (97 + y) << "  ";
        for(int x = 0; x < sizeX; x++)
        {
            // only print uif
            cout << data[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
//print board
void Board::printUI()
{
    // newline and 3 spaces
    cout << endl << "   ";
    
    //print abcde... etc
    for(int i = 0; i < sizeX; i++)
    {
        cout << (char) (97 + i);
    }
    cout << endl << endl;
    
    for(int y = 0; y < sizeY; y++)
    {
        // a is nr 97 on ascii table, 97 + 1 to char = b
        cout << (char) (97 + y) << "  ";
        for(int x = 0; x < sizeX; x++)
        {
            // only print uif
            cout << uif[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

char Board::getData(int x, int y)
{
    if(x < sizeX && y < sizeY && x >= 0 && y >= 0)
    {
        return data[x][y];
    }
    
    //if x or y arent in range
    return 'o';
    
}

// copy minecount from data to uif
void Board::moveToUIF(int x, int y)
{
    uif[x][y] = data[x][y];
}


// recursive function if minecount == 0
void Board::checkEmptyField(int x, int y)
{
    if(x >= 0 && y >= 0 && x < sizeX && y < sizeY)
    {
        if(data[x][y] == '0' && uif[x][y] == '.'){
            uif[x][y] = '0';
            checkEmptyField(x - 1, y - 1);
            checkEmptyField(x, y - 1);
            checkEmptyField(x + 1, y - 1);
            checkEmptyField(x - 1, y);
            checkEmptyField(x + 1, y);
            checkEmptyField(x -1, y + 1);
            checkEmptyField(x, y + 1);
            checkEmptyField(x + 1, y + 1);
        } else {
            moveToUIF(x, y);
        }
    }
}

// if data[x][y] contains mine, increment minecount
int Board::addToMinecount(int x, int y, int& minecount){
    if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
    {
        if(data[x][y] == 'M') minecount++;
    }
    return 0;
}


int Board::getGameStatus()
{
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            
            if(uif[x][y] == '.') {
                if(data[x][y] != 'm')
                {
                    return 0;
                }
            }
            // if all dots are mines, return 1
        }
    }
    return 1;
}