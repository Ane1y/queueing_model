#include "Maschine.hpp"

Maschine::Maschine(int knum, int snum, int dnum, int bnum) :
                rand_(),
                buffer_(bnum)
{
    initializeAll(snum, dnum, bnum);
    runLoop(knum);
}

void Maschine::initializeAll(int snum, int dnum, int bnum) {
    sources_.reserve(snum);
    devices_.reserve(dnum);

    double lambda;
    std::cout << "\nEnter lambda source";
    std::cin >> lambda;
    for(int i = 0; i < snum; i++) {
        Source s(lambda, rand_);
        sources_.push_back(s);
    }

    int a;
    int b;
       std::cout << "\nEnter a and b that is used to determine time of processing record by uniform distribution\n";
       std::cin >> a >> b;

    for(int i = 0; i < dnum; i++) {
        Device d(a, b);
        devices_.push_back(d);
    }
}

void Maschine::runLoop(int kmin) {
    int k = 0;
    while (k < kmin) {
       std::cout << "\n\n k =" << k + 1;

       printStatsforStep();

       minDevice = std::min_element(devices_.begin(), devices_.end(), [](const Device &a, const Device &b) {
            return a.getTime() < b.getTime(); });

       minSource =  std::min_element(sources_.begin(), sources_.end(), []( const Source &a, const Source &b ) {
           return a.getTime() < b.getTime(); } );

       if((minDevice->getTime() < minSource->getTime()) && !(minDevice->isFree())) {               //работаем с приборами
           if(buffer_.empty()) {
                std::cout << "\nDevice is waiting for your record";
                std::cout << "\nSelected device is: " << minDevice->getTime();
                std::cout << "\nSelected source is: " << minSource->getTime();

                minDevice->setFreeFlag(true);

                Record temp = formRecord();

                minDevice->processRecord(temp, rand_);

                sources_[temp.snum].addProceededRecord();
           } else {                                                                                //иначе обрабатываем с буфера

                Record temp = buffer_.getLastRecord();

                std::cout << "\nSelected device is: " << minDevice->getTime();
                std::cout << "\nProceed buffer record " << temp.time;

                minDevice->processRecord(temp, rand_);
                sources_[temp.snum].addProceededRecord();
           }
        } else {
           std::cout << "\nRecord was added to buffer: " << minSource->getTime();
           Record temp = formRecord();
           int denied = buffer_.addRecord(temp);
           if (denied >= 0) {
               sources_[denied].addDeniedRecord();
               std::cout << "\nRecord was denied from source num " << denied;
           }
        }
    k++;
    }
    printFinalStats();
}

void Maschine::printStatsforStep() const {
    std::cout << "\ndevice time: ";
    for(auto i : devices_) {
        std::cout <<  i.getTime() << " ";
    }

    std::cout << "\nsource time: ";
    for(auto i : sources_) {
        std::cout <<  i.getTime()  << " ";
    }
}
void Maschine::printFinalStats() const {
    std::cout << "\nDowntime are:\n";
    for(auto i : devices_) {
        std::cout << i .getDowntime() << " ";
    }
    std::cout << "\nsource time: ";
    for(auto i : sources_) {
        std::cout <<  i.getTime()  << " ";
    }

    std::cout << "\nnum generated record: ";
    for(auto i : sources_) {
        std::cout <<  i.getStatgen()  << " ";
    }

    std::cout << "\nnum proceeded record: ";
    for(auto i : sources_) {
        std::cout <<  i.getStatproceed()  << " ";
    }
    std::cout << "\nnum denied record: ";
    for(auto i : sources_) {
        std::cout <<  i.getDenied()  << " ";
    }
    std::cout << "\ntotal sum: ";
    for(auto i : sources_) {
        std::cout <<  i.getStatgen() - i.getStatproceed() -i.getDenied() << " ";
    }
}

Record Maschine::formRecord() {
    Record temp = {minSource->getTime(), minSource - sources_.begin()};

    minSource->generateRecord(rand_);

    return temp;
}