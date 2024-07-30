#include "../include/Geometry.h"
Geometry::Geometry(std::vector<Cell*> & _cells)
 : cells{_cells}
 {
    cell_bounds = {_cells[0]->getLeftBound()};
    for (Cell* _cell : _cells)
    {
        cell_bounds.push_back(_cell->getRightBound());
    }
 }

 int Geometry::getCellIndex(double _x0)
 {
    for (int i=0;  i < cell_bounds.size()-1; i++)
    {
        if (_x0 > cell_bounds[i] && _x0 < cell_bounds[i+1])
            return i;
    }
    return -1;
 }

 Cell* Geometry::getCell(int index)
 {
    return cells[index];
 }