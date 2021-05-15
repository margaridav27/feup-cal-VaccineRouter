#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H


#include <string>

class ApplicationCenter {
private:
    unsigned int locationNodeID;
    unsigned int vaccinesToReceive;
public:
    ApplicationCenter(unsigned int locationNodeId);
    unsigned int getLocationNodeId() const;
    unsigned int getVaccinesToReceive() const;
    void setVaccinesToReceive(unsigned int order);
    bool operator==(const ApplicationCenter &rhs) const;
};


#endif //VACCINEROUTER_APPLICATIONCENTER_H
