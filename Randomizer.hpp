#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <random>
#include <vector>
#include <stdexcept>

class Randomizer {

public:
    Randomizer();
    double NextDouble(double minValue, double maxValue);

private:
    std::mt19937 randomNumberGenerator;
};

#endif
