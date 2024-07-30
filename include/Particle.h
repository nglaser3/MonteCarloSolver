#pragma once
#include "Geometry.h"

class Particle
{
private:
    double _location;
    
    Geometry _geometry;

public:
    Particle(double _x0, Geometry _geom):_location{_x0},_geometry{_geom}{};
    double move();
    int cellIndex();
    ~Particle() = default;
};



