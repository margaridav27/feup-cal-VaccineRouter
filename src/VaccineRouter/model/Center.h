#ifndef VACCINEROUTER_CENTER_H
#define VACCINEROUTER_CENTER_H


#include <string>
#include "../graph/node/Node.h"

class Center {
protected:
    Node *node;
    std::string name;
    bool visited;
public:
    Center();
    Center(Node *node, std::string name);

    Node *getNode() const;
    const std::string &getName() const;

    bool isVisited() const;
    void setVisited();
    void setUnvisited();

    bool operator==(const Center &rhs) const;
};


#endif //VACCINEROUTER_CENTER_H
