#ifndef VACCINEROUTER_TIME_H
#define VACCINEROUTER_TIME_H

#include <string>
#include <iostream>

class Time {
private:
  unsigned int hour;
  unsigned int minute;
  unsigned int second;
public:
  Time(unsigned int hour, unsigned int minute, unsigned int second);
  Time(std::string timeStr);

  Time *getTime();
  void setTime(unsigned int hour, unsigned  int minute, unsigned int second);
  void setTime(std::string timeStr);

  Time *operator+(Time t);
  std::ostream &operator<<(std::ostream &o);


};
#endif //VACCINEROUTER_TIME_H
