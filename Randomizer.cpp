#include "Randomizer.hpp"
#include <iostream>

Randomizer::Randomizer() :
          randomNumberGenerator(std::random_device{}())
{}

double Randomizer::NextDouble(double minValue, double maxValue)
{
    if (minValue < 0.0 || maxValue < minValue) {
        throw std::invalid_argument("minValue and maxValue must be non-negative. maxValue must be greater than minvalue");
    }
    std::uniform_real_distribution<double> distribution(minValue, maxValue);
    return distribution(randomNumberGenerator);
}
