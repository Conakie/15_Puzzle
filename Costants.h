
#ifndef KIIYUO_15PUZZLE_COSTANTS_H
#define KIIYUO_15PUZZLE_COSTANTS_H

#include "Point.h"

namespace Costants
{
    constexpr int emptyLines{ 25 };
    const Point up   { 1,0 };
    const Point left { 0,1 };
    const Point down { -1,0 };
    const Point right{ 0,-1 };
}

#endif // !KIIYUO_15PUZZLE_COSTANTS_H