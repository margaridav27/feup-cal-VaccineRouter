#include "Time.h"
#include <sstream>

Time::Time() {
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second)
        : hour(hour), minute(minute), second(second) {}

// 04:30:04
Time::Time(std::string timeStr) {
    this->hour = std::stoi(timeStr.substr(0, 2));
    this->minute = std::stoi(timeStr.substr(4, 6));
    this->second = std::stoi(timeStr.substr(7, 9));
}

Time::Time(double hours) {
    int totalSeconds = (int) (hours * 3600.0);
    this->hour = totalSeconds / 3600;
    this->minute = (totalSeconds / 60) % 60;
    this->second = totalSeconds % 60;
}

Time Time::getTime() { return *this; }

void Time::setTime(unsigned int hour, unsigned int minute,
                   unsigned int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void Time::setTime(std::string timeStr) {
    this->hour = std::stoi(timeStr.substr(0, 2));
    this->minute = std::stoi(timeStr.substr(4, 6));
    this->second = std::stoi(timeStr.substr(7, 9));
}

Time Time::operator+(Time &t) const {
    unsigned int hour, minute, second;
    second = this->second + t.second;
    minute = this->minute + t.minute + (second / 60);
    hour = this->hour + t.hour + (minute / 60);
    minute %= 60;
    second %= 60;

    return Time(hour, minute, second);
}

bool Time::operator>(Time t) const {
    if (this->hour == t.hour) {
        if (this->minute == t.minute) {
            return this->second > t.second;
        }
        return this->minute > t.minute;
    }
    return this->hour > t.hour;
}

Time &Time::operator+=(const Time &t) {
    unsigned int hour, minute, second;
    second = this->second + t.second;
    minute = this->minute + t.minute + (second / 60);
    hour = this->hour + t.hour + (minute / 60);
    minute %= 60;
    second %= 60;

    this->hour = hour;
    this->minute = minute;
    this->second = second;
    return *this;
}

Time &Time::operator=(Time t) {
    if (this == &t)
        return *this;
    this->hour = t.hour;
    this->minute = t.minute;
    this->second = t.second;
    return *this;
}

std::string Time::getTimeStr() {
    std::stringstream ss;
    ss << this->hour << ":" << this->minute << ':' << this->second;
    return ss.str();
}

std::ostream &operator<<(std::ostream &o, Time *time) {
    o << time->getTimeStr();
    return o;
}
