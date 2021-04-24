#include "Coordinates.h"
#include <cmath>

Coordinates::Coordinates(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

double Coordinates::getLatitude() const { return this->latitude; }

double Coordinates::getLongitude() const { return this->longitude; }

void Coordinates::setLatitude(double lat) { this->latitude = lat; }

void Coordinates::setLongitude(double lon) { this->longitude = lon; }

double Coordinates::calculateEuclidianDistance(Coordinates c1, Coordinates c2) {
    return sqrt(pow((c1.latitude - c2.latitude), 2) + pow((c1.longitude - c2.longitude), 2));
}
