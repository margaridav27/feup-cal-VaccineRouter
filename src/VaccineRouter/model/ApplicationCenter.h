#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H

#include "../graph/node/Node.h"
#include <string>

class ApplicationCenter {
private:
    Node *node;
    std::string name;
    unsigned int vaccinesToReceive;
public:
    ApplicationCenter(Node *node, std::string name);
    Node *getNode() const;
    const std::string &getName() const;
    unsigned int getVaccinesToReceive() const;
    void setVaccinesToReceive(unsigned int order);
    bool operator==(const ApplicationCenter &rhs) const;
};


#endif //VACCINEROUTER_APPLICATIONCENTER_H
