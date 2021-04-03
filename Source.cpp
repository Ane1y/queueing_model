#include "Source.hpp"

#include <cmath>
Source::Source(double lambda, Randomizer &rand) :
  time_(0.0),
  statgen_(0),
  statproceed_(0),
  denied(0),
  lambda_(lambda)
{
    generateRecord(rand);
}

void Source::generateRecord(Randomizer &rand) {
    time_ += -1 / lambda_ * log(rand.NextDouble(0, 1));
    std::cout << "\nCurrent source time = " << time_ << std::endl;
    statgen_++;
}

double Source::getTime() const{
    return time_;
}


int Source::getStatgen() const {
    return statgen_;
}

int Source::getStatproceed() const {
    return statproceed_;
}

void Source::addProceededRecord() {
    statproceed_++;
}

void Source::addDeniedRecord() {
    denied++;
}

int Source::getDenied() const {
    return denied;
}

