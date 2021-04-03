#include "Buffer.hpp"

Buffer::Buffer(const size_t bnum) :
    bnum_(bnum)
{}

int Buffer::addRecord(const Record& record) {
    int status = -1;
    if(buffer_.size() >= bnum_) {
        status = buffer_.begin()->snum;
        buffer_.pop_front();
    }
    buffer_.push_back(record);

    std::cout << "\nWhat's in the buffer:";
    for(auto i : buffer_) {
        std::cout << i.time << " ";
    }
    return status;
}

Record Buffer::getLastRecord() {
    Record temp = buffer_.back();
    buffer_.pop_back();
    return temp;
}

bool Buffer::empty() {
    return buffer_.empty();
}