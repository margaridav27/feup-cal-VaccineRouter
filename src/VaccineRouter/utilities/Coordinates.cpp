#include "Coordinates.h"

Coordinates::Coordinates(double x,double y){
    this->x = x;
    this->y = y;
}
Coordinates::Coordinates(Coordinates *c){
    this->x = c->x;
    this->y = c->y;
}
