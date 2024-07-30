#pragma once
#include "../include/Particle.h"
#include "../include/MathFunctions.h"

double Particle::move()
{
    Cell* cell = _geometry.getCell(cellIndex());

    double _dist = sampleDistance(_location,cell->getTot()) * sampleDirection();
    
    _location += _dist;
    return _location;
}

int Particle::cellIndex()
{
    return _geometry.getCellIndex(_location);
}