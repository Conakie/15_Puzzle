
#include <iostream>
#include <Windows.h>
#include "Stuff.h"
#include "Costants.h"
#include "Tile.h"

void printEmptyLines(int linesToSkip)
{
    for (int i = 0; i < linesToSkip; ++i)
        std::cout << std::endl;
}

void swap(Tile& a, Tile& b)
{
    Tile c{ a };
    a = b;
    b = c;
}

void delay(int seconds)
{
    Sleep(seconds * 1000);
}

void quit()
{
    exit(0);
}