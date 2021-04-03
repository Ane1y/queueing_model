#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "Record.hpp"

#include <list>
#include <iostream>

class Buffer {
public:
    Buffer(const size_t bnum);
    int addRecord(const Record& record);        //возвращает номер источника. заявка из которого пошла в отказ
    Record getLastRecord();
    bool empty();

private:
    std::list<Record> buffer_;
    size_t bnum_;
};


#endif //BUFFER_HPP
