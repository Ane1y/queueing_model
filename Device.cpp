#include "Device.hpp"

Device::Device(int a, int b) :
  time_(0),
  stats_(0),
  a_(a),
  b_(b),
  downtime_(0),
  free(false)
{
    if(a >= b) {
        throw std::range_error("A must be less than B\n");
    }
}

int Device::processRecord(Record &record, Randomizer& rand) { //может буль?


    double processTime = (double)a_+(double)(b_ - a_) * rand.NextDouble(0.0, 1.0);
    std::cout << "\nprocess Time = " << processTime;

    if(record.time > time_) {        //если прибор простаивал
        free = false;
        downtime_ += record.time - time_;
        time_ = record.time + processTime;
    } else {
        time_ += processTime;
    }
    std::cout << "\nFinal time: " << time_;
    stats_++;

    return 0;
}

int Device::addRecordToStats(){
    return 0;
}

double Device::getTime() const{
    return time_;
}

int Device::getStats() const{
    return stats_;
}

double Device::getDowntime() const {
    return downtime_;
}

bool Device::isFree() const {
    return free;
}

void Device::setFreeFlag(bool free) {
    Device::free = free;
}

