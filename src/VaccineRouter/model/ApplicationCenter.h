#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H


#include <string>

class ApplicationCenter {
private:
    unsigned int locationNodeID;
    std::string name;
    unsigned int vaccinesToReceive;
public:
    ApplicationCenter(unsigned int locationNodeId, std::string name);
    ApplicationCenter(const ApplicationCenter &ac);
    unsigned int getLocationNodeId() const;
    const std::string &getName() const;
    unsigned int getVaccinesToReceive() const;
    void setVaccinesToReceive(unsigned int order);
    bool operator==(const ApplicationCenter &rhs) const;
};


#endif //VACCINEROUTER_APPLICATIONCENTER_H
