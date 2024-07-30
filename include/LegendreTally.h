#pragma once
//#include "Enumerations.h"
#include "Geometry.h"
#include <vector> 

class LegendreTally
{
private:
    int _order;
    std::vector<double> expanded_coeffs;
    std::vector<double> end_coeffs;
    double transformDomains(double x0);
    std::vector<double> calcLegendre(double x0);
    double _left,_right;
    std::vector<double> xs;
    Geometry geom;

public:
    LegendreTally(int order, double left, double right, Geometry & _geom, std::vector<double> interaction_xs);
    void expandBatch(std::vector<double> interactions);
    void FinalizeFlux(int batches, int accuracy);
    ~LegendreTally() = default;
};

