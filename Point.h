
#ifndef KIIYUO_15PUZZLE_POINT_CLASS_H
#define KIIYUO_15PUZZLE_POINT_CLASS_H

class Point
{
public:
    Point() = default;
    Point(int x, int y)
        : m_x { x }
        , m_y { y }
    {
    }
    Point(const Point& point)
    {
        m_x = point.m_x;
        m_y = point.m_y;
    }

    void printPoint() const;
    bool canBeSet(int x, int y)   const;
    bool canBeSet(const Point& point) const;

    void setPoint(int x, int y);
    void setPoint(Point point);

    const int& getX() const { return m_x; }
    const int& getY() const { return m_y; }

    void operator= (const Point& point);
    friend Point operator+ (const Point& point1, const Point& point2);
    friend Point operator- (const Point& point1, const Point& point2);
    void operator+= (const Point& point);
    void operator-= (const Point& point);
private:
    int m_x{ 0 };
    int m_y{ 0 };
};

#endif // !KIIYUO_15PUZZLE_TILE_CLASS_H