#ifndef SRC_APPLICATIONCENTER_H
#define SRC_APPLICATIONCENTER_H


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


#endif //SRC_APPLICATIONCENTER_H
