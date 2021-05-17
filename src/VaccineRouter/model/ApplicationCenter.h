#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H

#include "../graph/node/Node.h"
#include "Center.h"
#include <string>

class ApplicationCenter : public Center {
private:
    unsigned int vaccinesToReceive;
public:
    ApplicationCenter();
    ApplicationCenter(Node *node, const std::string& name);
    unsigned int getVaccinesToReceive() const;
    void setVaccinesToReceive(unsigned int order);
    bool operator==(const ApplicationCenter *rhs) const;
};


#endif //VACCINEROUTER_APPLICATIONCENTER_H
