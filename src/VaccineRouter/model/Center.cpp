#include "Center.h"

#include <utility>

Center::Center() :
        node(nullptr),
        name("undefined"),
        visited(false) {}

Center::Center(Node *node, std::string name) :
        node(node),
        name(std::move(name)),
        visited(false) {}

Node *Center::getNode() const { return this->node; }

const std::string &Center::getName() const { return this->name; }

bool Center::isVisited() const { return this->visited; }

void Center::setVisited() { this->visited = true; }

void Center::setUnvisited() { this->visited = false; }

bool Center::operator==(const Center &rhs) const {
    return node == rhs.node &&
           name == rhs.name;
}





