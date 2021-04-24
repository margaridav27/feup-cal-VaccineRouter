#ifndef SRC_COORDINATES_H
#define SRC_COORDINATES_H


class Coordinates {
private:
    double latitude;
    double longitude;
public:
    Coordinates(double latitude, double longitude);

    double getLatitude() const;
    double getLongitude() const;

    void setLatitude(double lat);
    void setLongitude(double lon);

    static double calculateEuclidianDistance(Coordinates c1, Coordinates c2);
};


#endif //SRC_COORDINATES_H
