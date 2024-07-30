#pragma once

#include <vector>
class Cell
{
private:
    std::vector<double> _bounds;
    std::vector<double> _props;
public:
    Cell(double _left, double _right, double _absxs, double _sctxs, double _fisxs);
    double getLeftBound();
    double getRightBound();
    double getAbs();
    double getSct();
    double getFis();
    double getTot();
    ~Cell() = default;
};



