
#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Point.h"
#include "Direction.h"
#include "Stuff.h"
#include "Costants.h"
#include "Random.h"



void Board::resetBoard()
{
    // set the table as won by default
    int x{ 1 };
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m_board[i][j].setTile(x);
            ++x;
        }
    }
    m_board[3][3].setTile(0);
}

void Board::randomizeBoard()
{
    for (int i = 0; i < 1000; ++i)
    {
        switch (Random::get(0, 3))
        {
        case 0:
            move(Direction::up);
            break;
        case 1:
            move(Direction::right);
            break;
        case 2:
            move(Direction::down);
            break;
        case 3:
            move(Direction::left);
            break;
        default:
            std::cout << "Error!\n";
            break;
        }
    }
}

void Board::move(Direction direction)
{
    switch (direction)
    {
    case Direction::up:
        if (isOutOfBounds(getSpace() - Costants::up))
        {
            swap(getSpace() - Costants::up);
        }
        else
        {
        }
        break;
    case Direction::left:
        if (isOutOfBounds(getSpace() - Costants::left))
        {
            swap(getSpace() - Costants::left);
        }
        else
        {
        }
        break;
    case Direction::down:
        if (isOutOfBounds(getSpace() - Costants::down))
        {
            swap(getSpace() - Costants::down);
        }
        else
        {
        }
        break;
    case Direction::right:
        if (isOutOfBounds(getSpace() - Costants::right))
        {
            swap(getSpace() - Costants::right);
        }
        else
        {
        }
        break;
    default:
        break;
    }
}

bool Board::checkForWin()
{
    int x{ 1 };
    // when it is eqaul to 15 the player won
    int willWin{ 0 };
    // increase willWin every time x is the same as the tile
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (m_board[i][j].getTile() == x)
            {
                ++willWin;
            }
            else
            {

            }
            ++x;
        }
    }
    // the player will win when willWin is 15 and the last tile is the empty space
    if (willWin == 15 && m_board[3][3].getTile() == 0)
        return true;
    else
        return false;
}

void Board::printTile(Point point) const
{
    std::cout << m_board[point.getX()][point.getY()];
}

bool Board::isOutOfBounds(Point point) const
{
    if (point.getX() < 4 && point.getX() >= 0)
    {
        if (point.getY() < 4 && point.getY() >= 0)
        {
            return true;
        }
    }
    return false;
}

Tile Board::getTile(Point point) const
{
    if (!isOutOfBounds(point))
        return m_board[point.getX()][point.getY()];
    else
        return Tile(-1);
}

Point Board::getSpace() const
{
    Point space{};
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (m_board[i][j].isEmpty())
            {
                space.setPoint(i, j);
            }
        }
    }
    return space;
}

void Board::swap(Point b)
{
    Point a{ getSpace() };
    Tile c{ 0 };
    c = m_board[a.getX()][a.getY()];
    m_board[a.getX()][a.getY()] = m_board[b.getX()][b.getY()];
    m_board[b.getX()][b.getY()] = c;
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    printEmptyLines(Costants::emptyLines);
    std::cout << "-----------------\n";
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << '|' << board.m_board[i][j];
        }
        std::cout << "|\n-----------------\n";
    }
    return out;
}
