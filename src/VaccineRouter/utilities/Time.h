#ifndef VACCINEROUTER_TIME_H
#define VACCINEROUTER_TIME_H

#include <iostream>
#include <string>

/**
 * class Time
 */
class Time {
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

public:
    /**
     * constructor
     */
    Time();

    /**
     * constructor
     * @param hour
     * @param minute
     * @param second
     */
    Time(unsigned int hour, unsigned int minute, unsigned int second);

    /**
     * constructor
     * @param timeStr
     */
    Time(std::string timeStr);

    /**
     * constructor
     * @param hours
     */
    Time(double hours);

    /**
     * @return time copy
     */
    Time getTime();

    /**
     * @return time in string form
     */
    std::string getTimeStr();

    /**
     * sets current time to parameters received
     * @param hour
     * @param minute
     * @param second
     */
    void setTime(unsigned int hour, unsigned int minute, unsigned int second);

    /**
     * sets current time to string received "xx:xx:xx"
     * @param timeStr
     */
    void setTime(std::string timeStr);

    /**
     * @param t
     * @return the sum of both times
     */
    Time operator+(Time &t) const;

    /**
     * @param t
     * @return true if self > t, false otherwise
     */
    bool operator>(Time t) const;

    /**
     * @param t
     * @return true if self is equal to t, false otherwise
     */
    Time &operator=(Time t);

    /**
     * @param t
     * @return self + t time
     */
    Time &operator+=(const Time &t);
};

std::ostream &operator<<(std::ostream &o, Time *time);

#endif // VACCINEROUTER_TIME_H
