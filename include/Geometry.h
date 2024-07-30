#pragma once
#include "Cell.h"
#include <vector>

class Geometry
{
private:
    std::vector<Cell*> cells;
    std::vector<double> cell_bounds;
public:
    Geometry(std::vector<Cell*> & _cells);
    int getCellIndex(double _x0);
    Cell* getCell(int index);
    ~Geometry() = default;
};
