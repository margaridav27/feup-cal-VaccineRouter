#ifndef VACCINEROUTER_TIME_H
#define VACCINEROUTER_TIME_H

#include <iostream>
#include <string>

class Time {
private:
  unsigned int hour;
  unsigned int minute;
  unsigned int second;

public:
  Time();
  Time(unsigned int hour, unsigned int minute, unsigned int second);
  Time(std::string timeStr);
  Time(double hours);
  Time getTime();
  void setTime(unsigned int hour, unsigned int minute, unsigned int second);
  void setTime(std::string timeStr);
  Time operator+(Time &t) const;
  bool operator>(Time t) const;
  Time &operator=(Time t);
  Time &operator+=(const Time &t);
  std::ostream &operator<<(std::ostream &o) const;
};

#endif // VACCINEROUTER_TIME_H
