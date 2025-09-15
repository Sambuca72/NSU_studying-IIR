#pragma once
#include "Shape.hpp"

class Point{
private:
    int _x, _y;
public:
    Point(): _x(0), _y(0) {}

    Point(int xVal, int yVal) : _x(xVal), _y(yVal){}

    int GetX() const{ return _x; }
    int GetY() const{ return _y; }

    void SetX(int xVal) { _x = xVal; }
    void SetY(int yVal) { _y = yVal; }

    void Draw(){
        std::cout << "point at (" << _x << ", " << _y <<")\n";
    }
};