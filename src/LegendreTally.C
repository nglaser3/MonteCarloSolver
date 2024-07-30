#pragma once
#include <iostream>
#include "../include/MathFunctions.h"
#include "../include/LegendreTally.h"
#include <cmath>
//Works::
LegendreTally::LegendreTally(
    int order, double left, double right, Geometry & _geom, 
    std::vector<double> interaction_xs)
: _order{order},  
  expanded_coeffs(order+1,0.0), 
  end_coeffs(order+1,0.0),
  _left{left},
  _right{right},
  xs{interaction_xs},
  geom{_geom}
{
}

double LegendreTally::transformDomains(double x0)
{
    return 2*(x0-_left)/(_right - _left) - 1 ;
}
std::vector<double> LegendreTally::calcLegendre(double x0)
{
    double _x = transformDomains(x0);

    std::vector<double> vals{1};

    if (_order == 0) return vals;

    vals.push_back(_x);

    if (_order == 1) return vals;
    
    for (int i = 1; i < _order; i++)
    {
       double _value = ((2*i+1) * _x * vals[i] - i*vals[i-1])/(i+1);
       vals.push_back(_value);
    }
    return vals;
}

void LegendreTally::expandBatch(std::vector<double> interactions)
{   
    for (double x0 : interactions)
    {
        std::vector<double> place_holder = calcLegendre(x0);
        double _xs{xs[geom.getCellIndex(x0)]};
        for (int n = 0; n <= _order; n++)
        {
            expanded_coeffs[n] += place_holder[n] / _xs;
        }
    }
    for (int i = 0; i <=_order; i++)
    {
        end_coeffs[i] += expanded_coeffs[i] / interactions.size();
        expanded_coeffs[i] = 0.0;
    }
}




void printresults(std::vector<double> x, std::vector<double> y)
{
    std::cout<<"x,y";
    for (int i = 0; i < x.size(); i++)
    {
        std::cout<<x[i]<<","<<y[i]<<std::endl;
    }
}

void LegendreTally::FinalizeFlux(int batches, int accuracy)
{
    double _batches = batches;
    for (int n = 0; n <= _order; n++)
    {
        end_coeffs[n] /= _batches;
    }

    std::vector<double> _xlocs;
    std::vector<double> _yvals;
    double _x0;
    
    for (int i = 0; i <= accuracy; i++)
    {
        _x0 = (_right-_left)*(i/accuracy)+_left;
        _xlocs.push_back(_x0);
        double _y0{0.0};
        for (int n = 0; n <= _order; n++)
        {
            _y0 += calcLegendre(_x0)*end_coeffs[n];
        }
        _yvals.push_back(_y0);
    }
    printresults(_xlocs,_yvals);
}


