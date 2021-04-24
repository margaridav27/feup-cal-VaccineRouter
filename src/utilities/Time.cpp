#include "Time.h"


Time::Time(unsigned int minutes, unsigned int hours) : minutes(minutes), hours(hours) {}

unsigned int Time::getMinutes() const { return this->minutes; }

unsigned int Time::getHours() const { return this->hours; }

void Time::setMinutes(unsigned int m) { this->minutes = m; }

void Time::setHours(unsigned int h) { this->hours = h; }

Time Time::calculateTimeWindow(Time t1, Time t2) {
    return Time(0, 0);
}
