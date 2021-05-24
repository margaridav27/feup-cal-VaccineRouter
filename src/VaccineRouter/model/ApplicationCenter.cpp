#include "ApplicationCenter.h"
#include <fstream>


ApplicationCenter::ApplicationCenter() : Center() {
  this->vaccinesToReceive = 0;
}

ApplicationCenter::ApplicationCenter(Node *node, const std::string &name)
    : Center(node, name) {
  this->vaccinesToReceive = 0;
}

unsigned int ApplicationCenter::getVaccinesToReceive() const {
  return this->vaccinesToReceive;
}

void ApplicationCenter::setVaccinesToReceive(unsigned int order) {
  this->vaccinesToReceive = order;
}

bool ApplicationCenter::operator==(const ApplicationCenter *rhs) const {
  return this->node->getId() == rhs->getNode()->getId() &&
         name == rhs->getName();
}

std::ostream &operator<<(std::ostream &out, ApplicationCenter *ac) {
  out << "id : " << ac->getNode()->getId() << "  name: "
      << ac->getName() + "  "
                         "vaccines: "
      << ac->getVaccinesToReceive() << std::endl;
  return out;
}
