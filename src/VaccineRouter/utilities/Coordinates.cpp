#include "Coordinates.h"
#include <math.h>

Coordinates::Coordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

Coordinates::Coordinates(Coordinates *c) {
    this->x = c->x;
    this->y = c->y;
}

Coordinates *Coordinates::getCoordinates() {
    return this;
}

double Coordinates::getX() const {
    return this->x;
}

double Coordinates::getY() const {
    return this->y;
}

void Coordinates::setCoordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

double Coordinates::calculateEuclideanDistance(Coordinates c) const{
    return pow(std::sqrt(pow((this->x - c.getX()), 2) + pow((this->y - c.getY()), 2)), 2);
}
