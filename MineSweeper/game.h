//
//  game.h
//  MineSweeper
//
//  Created by DwiteeKP on 07/05/15.
//  Copyright (c) 2015 DwiteeKP. All rights reserved.
//

#ifndef MineSweeper_game_h
#define MineSweeper_game_h
#include "board.h"

class Game
{
public:
    Game(int minecount, int x, int y);
    ~Game();
    int update(int x, int y);
private:
    //game board
    Board board;
};
#endif
