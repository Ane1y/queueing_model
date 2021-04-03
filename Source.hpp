#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <iostream>

#include "Randomizer.hpp"

class Source {
public:
    Source(double lambda, Randomizer &rand);


    void generateRecord(Randomizer &rand);
   // void addRecordtoStats();

    double getTime() const;
    int getStatgen() const;
    int getStatproceed() const;
    int getDenied() const;

    void addProceededRecord();
    void addDeniedRecord();

private:
    double lambda_;
    double time_;
    int statgen_;
    int statproceed_;
    int denied;

};
#endif //SOURCE_HPP
