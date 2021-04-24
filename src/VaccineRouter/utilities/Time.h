#ifndef SRC_TIME_H
#define SRC_TIME_H


class Time {
private:
    unsigned int minutes;
    unsigned int hours;
public:
    Time(unsigned int minutes, unsigned int hours);

    unsigned int getMinutes() const;
    unsigned int getHours() const;

    void setMinutes(unsigned int m);
    void setHours(unsigned int h);

    //TODO - operators

    //TODO - operators needed
    static Time calculateTimeWindow(Time t1, Time t2);
};


#endif //SRC_TIME_H
