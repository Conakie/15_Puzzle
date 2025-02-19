
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Board.h"
#include "Stuff.h"



static void game()
{
    char action{ '0' };
    Board board{};
    board.randomizeBoard();

    while (!board.checkForWin() && action != 'q')
    {
        std::cout << board;
        std::cout << "Cosa fai?\n(w/a/s/d = up/right/down/left)\n(q = quit)\n";
        action = Input::character();
        board.move(static_cast<Direction>(action));
    }

    if (board.checkForWin())
    {
        std::cout << "You won!\n"
            << "Do you want to play again?\n(y/s = si/yes)\n(n = no)\n";
    }
    else if (action == 'q')
    {
        std::cout << "Killing the app... Adios.\n";
        delay(3);
    }
}

int main()
{
    system("Color 07");
    bool play{ true };
    std::cout << "Do you want to play?\n(y/s = si/yes)\n(n = no)\n";
    while (play)
    {
        switch (Input::character())
        {
        case 's':
            [[fallthrough]];
        case 'y':
            game();
            break;
        default:
            play = false;
            break;
        }
    }
    std::cout << "Nanre: \"Closing the console...\"\n";
    delay(3);
    return 0;
}
/*
Board things
    Display the game board
    Display an individual tile
    Randomize the starting state
    Slide tiles
    Determine if win condition reached
User things
    -Get commands from user
    -Handle invalid input
    Allow the user to quit before winning
*/