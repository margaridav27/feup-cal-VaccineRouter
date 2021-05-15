#include "ApplicationCenter.h"

#include <utility>

ApplicationCenter::ApplicationCenter(Node *node, std::string name) :
        node(node),
        name(name),
        vaccinesToReceive(0) {}

Node *ApplicationCenter::getNode() const {
    return this->node;
}

const std::string &ApplicationCenter::getName() const {
    return this->name;
}

unsigned int ApplicationCenter::getVaccinesToReceive() const {
    return this->vaccinesToReceive;
}

void ApplicationCenter::setVaccinesToReceive(unsigned int order) {
    this->vaccinesToReceive = order;
}

bool ApplicationCenter::operator==(const ApplicationCenter &rhs) const {
    return this->node->getId() == rhs.getNode()->getId() &&
           name == rhs.name;
}
