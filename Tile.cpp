
#include <iostream>
#include "Tile.h"

void Tile::printTile() const
{
    std::cout << m_tile;
}

void Tile::setTile(int value)
{
    m_tile = value;
}

void Tile::operator=(const Tile& tile)
{
    m_tile = tile.m_tile;
}

std::ostream& operator<< (std::ostream& out, const Tile& tile)
{
    if (tile.m_tile == 0)// space
    {
        out << "   ";
    }
    else if (tile.m_tile < 10)// single digit
    {
        out << " " << tile.m_tile << " ";
    }
    else// double digit
    {
        out << tile.m_tile << " ";
    }
    return out;
}