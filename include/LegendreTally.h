#pragma once
//#include "Enumerations.h"
#include "Geometry.h"
#include <vector> 

class LegendreTally
{
private:
    int _order;
    std::vector<std::vector<double>> base_coeffs;
    std::vector<std::vector<double>> base_powers;
    std::vector<double> expanded_coeffs;
    std::vector<double> end_coeffs;
    double transformDomains(double x0);
    double calcLegendre(double x0, int n);
    double _left,_right;
    std::vector<double> xs;
    Geometry geom;

public:
    std::vector<std::vector<double>> getBaseCoeffs();
    std::vector<std::vector<double>> getBasePowers();
    LegendreTally(int order, double left, double right, Geometry & _geom, std::vector<double> interaction_xs);
    void expandBatch(std::vector<double> interactions);
    void FinalizeFlux(int batches, int accuracy);
    ~LegendreTally() = default;
};

