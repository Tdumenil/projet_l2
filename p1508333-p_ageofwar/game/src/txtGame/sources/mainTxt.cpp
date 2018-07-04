//
// Created by skugga on 17/03/17.
//

#include "../headers/winTxt.h"
#include "../headers/txtGame.h"
#include <iostream>
int main ( int argc, char** argv ) {
    termClear();
    Game game;
    txtBoucle(game);
    termClear();
    return 0;
}
