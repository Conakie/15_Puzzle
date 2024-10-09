
#ifndef KIIYUO_15PUZZLE_TILE_CLASS_H
#define KIIYUO_15PUZZLE_TILE_CLASS_H

class Tile
{
public:
    Tile() = default;
    Tile(int value)
        : m_tile { value }
    {
    }
    Tile(const Tile&)
    {

    }
    
    void printTile() const;
    void setTile(int value);
    
    bool isEmpty() const { return m_tile == 0; }
    const int& getTile() const { return m_tile; };

    void operator= (const Tile& tile);
    friend std::ostream& operator<< (std::ostream& out, const Tile& tile);
private:
    int m_tile{ 0 };
};

#endif // !KIIYUO_15PUZZLE_TILE_CLASS_H