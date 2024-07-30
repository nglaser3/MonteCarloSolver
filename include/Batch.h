#pragma once

#include "Particle.h"
#include "Geometry.h"
#include <vector>
class Batch
{
private:
    std::vector<double> fission_sites;
    std::vector<double> birth_sites;
    std::vector<double> flux_vector;
    std::vector<double> interaction_sites;
    double k_eff;
public:
    Batch(std::vector<double> sites_for_birth, int bins);
    ~Batch() = default;

    double getBatchKeff();

    std::vector<double> getBatchFlux();

    double getBatchAverageFlux();

};

