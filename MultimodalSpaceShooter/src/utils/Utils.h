#ifndef UTILS_H
#define UTILS_H

const float PI = 3.14159265f;

//////////////////////////////////////////////////
/// Some utility funcitons as degres to radians conversion
//////////////////////////////////////////////////
namespace utils
{
    template <typename T>
    inline T degToRad(const T angle)
    {
        return (angle * PI) / 180.f;
    }
}

#endif // UTILS_H
