#include "Time.h"

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) :
        hour(hour),
        minute(minute),
        second(second) {}

//04:30:04
Time::Time(std::string timeStr) {
    this->hour = std::stoi(timeStr.substr(0, 2));
    this->minute = std::stoi(timeStr.substr(4, 6));
    this->second = std::stoi(timeStr.substr(7, 9));
}

Time *Time::getTime() {
    return this;
}

void Time::setTime(unsigned int hour, unsigned int minute, unsigned int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void Time::setTime(std::string timeStr) {
    this->hour = std::stoi(timeStr.substr(0, 2));
    this->minute = std::stoi(timeStr.substr(4, 6));
    this->second = std::stoi(timeStr.substr(7, 9));
}

Time *Time::operator+(Time t) const {
    unsigned int hour, minute, second;
    second = this->second + t.second;
    minute = this->minute + t.minute + (second / 60);
    hour = this->hour + t.hour + (minute / 60);
    minute %= 60;
    second %= 60;

    return new Time(hour, minute, second);
}

std::ostream &Time::operator<<(std::ostream &o) const {
    o << this->hour << ":" << this->minute << ":" << this->second << std::endl;
    return o;
}
