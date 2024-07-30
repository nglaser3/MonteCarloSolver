#include "../include/Cell.h"

Cell::Cell(double _left, double _right, double _absxs, double _sctxs, double _fisxs)
  : _bounds{_left,_right},
    _props{_absxs,_sctxs,_fisxs,_absxs+_sctxs+_fisxs}
{
}

double Cell::getLeftBound()
{
    return _bounds[0];
}
double Cell::getRightBound()
{
    return _bounds[1];
}

double Cell::getAbs()
{
    return _props[0];
}

double Cell::getSct()
{
    return _props[1];
}

double Cell::getFis()
{
    return _props[2];
}

double Cell::getTot()
{
    return _props[3];
}