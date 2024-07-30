#pragma once
#include <cstdlib>

double Random()
{
    double _top =  std::rand();
    double _bottom = RAND_MAX;
    return _top/_bottom;
}