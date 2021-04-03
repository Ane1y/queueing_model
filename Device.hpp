#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <random>

#include "Record.hpp"
#include "Source.hpp"

class Device {
public:
    Device(int a, int b);
    int processRecord(Record &record, Randomizer& rand);
    int addRecordToStats();

    double getTime() const;
    int getStats() const;
    double getDowntime() const;

   bool isFree() const;
    void setFreeFlag(bool free);


private:
    double time_;
    int stats_;

    int a_; //используются для определения времени обработки заявки по распределительному закону
    int b_;
    double downtime_;
    bool free;
};


#endif