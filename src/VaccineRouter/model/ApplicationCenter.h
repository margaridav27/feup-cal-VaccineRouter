#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H


class ApplicationCenter {
private:
    unsigned int locationNodeID;
    unsigned int vaccinesToReceive;
public:
    ApplicationCenter(unsigned int locationNodeId);
    unsigned int getLocationNodeId() const;
    unsigned int getVaccinesToReceive() const;
    void setVaccinesToReceive(unsigned int order);
};


#endif //VACCINEROUTER_APPLICATIONCENTER_H
