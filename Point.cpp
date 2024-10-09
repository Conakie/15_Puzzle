
#include "Point.h"

void Point::printPoint() const
{
}

bool Point::canBeSet(int x, int y) const
{
    if (x < 4 && x >= 0)
    {
        if (y < 4 && y >= 0)
        {
            return true;
        }
    }
    return false;
}

bool Point::canBeSet(const Point& point) const
{
    return canBeSet(point.getX(), point.getY());
}

void Point::setPoint(int x, int y)
{
    if (canBeSet(x, y))
    {
        m_x = x;
        m_y = y;
    }
    else
    {

    }
}

void Point::setPoint(Point point)
{
    m_x = point.getX();
    m_y = point.getY();
}

void Point::operator=(const Point& point)
{
    m_x = point.m_x;
    m_y = point.m_y;
}

void Point::operator+=(const Point& point)
{
    m_x += point.m_x;
    m_y += point.m_y;
}

void Point::operator-=(const Point& point)
{
    m_x -= point.m_x;
    m_y -= point.m_y;
}

Point operator+(const Point& point1, const Point& point2)
{
    return { point1.m_x + point2.m_x, point1.m_y + point2.m_y };
}

Point operator-(const Point& point1, const Point& point2)
{
    return { point1.m_x - point2.m_x, point1.m_y - point2.m_y };
}
