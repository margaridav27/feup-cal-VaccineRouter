#ifndef SRC_COORDINATES_H
#define SRC_COORDINATES_H


class Coordinates {
    double x, y;
public:
    Coordinates(double x, double y);
    Coordinates(Coordinates *c);
    Coordinates *getCoordinates();
    double getX() const;
    double getY() const;
    void setCoordinates(double x, double y);
    double calculateEuclideanDistance(Coordinates c) const;
};


#endif //SRC_COORDINATES_H
