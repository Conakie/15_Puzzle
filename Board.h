
#ifndef KIIYUO_15PUZZLE_BOARD_CLASS_H
#define KIIYUO_15PUZZLE_BOARD_CLASS_H

#include "Tile.h"
#include "Point.h"
#include "Direction.h"

class Board
{
public:
    Board() = default;
    // set the board to the win state
    void resetBoard();
    // randomize the tile of the board. It may take some time
    void randomizeBoard();
    // moves the space based on @direction
    void move(Direction direction);
    // check if the boad is in it's win state
    bool checkForWin();
    // print a single tile
    void printTile(Point point) const;
    // check if the point is outside the board
    bool isOutOfBounds(Point point) const;
    // get a single tile
    Tile getTile(Point point) const;
    // get the empty tile
    Point getSpace() const;

    friend std::ostream& operator<< (std::ostream& out, const Board& board);
private:
    // swap the space with a tile in point position
    void swap(Point b);
    // the board
    Tile m_board[4][4]{
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
};

#endif // !KIIYUO_15PUZZLE_BOARD_CLASS_H