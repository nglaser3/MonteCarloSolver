#pragma once
#include "Random.h"
#include <cmath>
#include <vector>

double sampleDistance(double _x0, double _totalxs)
{
    return std::log(Random())/_totalxs;
}

double sampleDirection()
{
    return (2*Random() - 1);
}

int sampleInteraction(double _x0, std::vector<double> _props)
{
    double _abs{_props[0]}; 
    double _sct{_props[1]}; 
    double _fis{_props[2]}; 
    double _tot{_props[3]};

    double _r{Random()};

    if (_r<_abs/_tot) 
        return 0;

    else if (_r< _sct/_tot) 
        return 1;

    else 
        return 2; 
}

double factorial(int input)
{
    double value = 1;
    for (int i = 1; i <= input; i++)
    {
        value *= i;
    }
    return value;
}

double binomial_coeff(int n, int k)
{
    return factorial(n) / factorial(k) / factorial(n-k);
}