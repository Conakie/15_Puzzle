
#ifndef KIIYUO_INPUT_H
#define KIIYUO_INPUT_H

#include <string_view>

namespace Input
{

    int integer();

    double real();

    char character();

    // the string input isn't working properly, send help
    std::string_view string();

}

#endif // !KIIYUO_INPUT_H