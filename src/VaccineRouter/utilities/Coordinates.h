#ifndef SRC_COORDINATES_H
#define SRC_COORDINATES_H

/**
 * class Coordinates
 */
class Coordinates {
  double x, y;

public:
  /**
   * constructor
   * @param x
   * @param y
   */
  Coordinates(double x, double y);
  /**
   * constructor
   * @param c
   */
  Coordinates(Coordinates *c);

  /**
   *
   * @return coordinate x
   */
  double getX() const;
  /**
   *
   * @return coordinate y
   */
  double getY() const;

  /**
   *
   * @param c
   * @return the distance between the self coordinates and the c coordinates
   */
  double calculateEuclideanDistance(Coordinates c) const;
};

#endif // SRC_COORDINATES_H
