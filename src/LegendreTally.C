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
  base_coeffs{}, 
  base_powers{}, 
  expanded_coeffs(order+1,0.0), 
  end_coeffs(order+1,0.0),
  _left{left},
  _right{right},
  xs{interaction_xs},
  geom{_geom}
{
    for (int n = 0; n <= _order; n++)
    {
        int _top_bound = floor(n/2);
        
        std::vector<double> cur_coeffs{};
        std::vector<double> cur_powers{};
        double coef;
        for (int k = 0; k <= _top_bound; k++)
        {
            cur_powers.push_back(n-2*k);
            coef = std::pow(-1,k) / std::pow(2,n) * binomial_coeff(n,k) 
            * binomial_coeff(2*n-2*k,n);
            cur_coeffs.push_back(coef);
        }
        base_coeffs.push_back(cur_coeffs);
        base_powers.push_back(cur_powers);
    }
}

double LegendreTally::transformDomains(double x0)
{
    return 2*(x0-_left)/(_right - _left) - 1 ;
}
double LegendreTally::calcLegendre(double x0, int n)
{
    double _x = transformDomains(x0);
    double val = 0.0;
    for (int i = 0; i < base_powers[n].size(); i++)
    {
        val += base_coeffs[n][i] * std::pow(_x,base_powers[n][i]);
    }
    return val;
}

void LegendreTally::expandBatch(std::vector<double> interactions)
{
    for (int n = 0; n <= _order; n++)
    {
        for (double x0 : interactions)
        {
            expanded_coeffs[n] += calcLegendre(x0,n) / xs[geom.getCellIndex(x0)];
        }
        expanded_coeffs[n] /= interactions.size();
        end_coeffs[n] += expanded_coeffs[n];
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
            _y0 += calcLegendre(_x0,n)*end_coeffs[n];
        }
        _yvals.push_back(_y0);
    }
    printresults(_xlocs,_yvals);
}

std::vector<std::vector<double>> LegendreTally::getBaseCoeffs()
{
    return base_coeffs;
}

std::vector<std::vector<double>> LegendreTally::getBasePowers()
{
    return base_powers;
}

