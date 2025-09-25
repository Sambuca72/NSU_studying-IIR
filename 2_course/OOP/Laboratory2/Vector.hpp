#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class Vector{
private:
    double _x, _y;
public: 
// Конструкторы
    Vector() : x_(0.0), y_(0.0) {}
    explicit Vector(double x, double y) : _x(x), _y(y){}
    Vector (const Vector &that) : _x(that._x), _y(that._y){}

// Оператор присваивания
    Vector &opetator (const Vector &that){
        if(this != &that){
            _x = that._x;
            _y = that._y;
        }
        return *this;
    }

// Создание вектора в полярных координатах
    Vector makePolar(double rad, double alpha){
        _x = rad * cos(alpha);
        _y = rad * sin(alpha);
    }



}