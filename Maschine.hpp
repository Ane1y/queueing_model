#ifndef MASCHINE_HPP
#define MASCHINE_HPP

#include <vector>
#include <iostream>

#include "Source.hpp"
#include "Device.hpp"
#include "Buffer.hpp"
#include "Randomizer.hpp"

class Maschine {
public:
    Maschine(int knum, int snum, int dnum, int bnum);
    void printStatsforStep() const;
    void printFinalStats() const;

    void initializeAll(int snum, int dnum, int bnum);
    void runLoop(int kmin);

    Record formRecord();

private:
    Randomizer rand_;

    std::vector<Source> sources_;
    std::vector<Device> devices_;

    std::vector<Source>::iterator minSource;
    std::vector<Device>::iterator minDevice;

    Buffer buffer_;
};


#endif //MASCHINE_HPP
