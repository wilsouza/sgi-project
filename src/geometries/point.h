#ifndef _INCLUDED_POINT_
#define _INCLUDED_POINT_

namespace geometries {
  class Point
  {
  public:
    virtual ~Point();
    Point(float x, float y);
    Point(const Point& other);

    const float& getX() const;
    const float& getY() const;
    const float& getZ() const;

    void setX(float newX);
    void setY(float newY);
    void setZ(float newZ);

    Point& operator=(const Point& other);
    Point& operator*=(float number);

  private:
    float x_, y_, z_;
  };
}

#endif
