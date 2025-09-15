#pragma once

class Circle{
private:
    Point _center;
    int _radius;
public:
    Circle() : _center(0, 0), _radius(0) {}

    Circle(const Point& cent, const int rad) : _center(cent), _radius(rad) {}

    Point Getcenter() const { return _center; }
    int Getradius() const { return _radius; }

    void Setcenter(const Point& cent) { _center = cent; }
    void Setradius(const int rad) { _radius = rad; }

    void Draw(){
        std::cout << "circle at (" << _center.GetX() << ", " << _center.GetY() <<"), rad = " << _radius << "\n";
    }
};