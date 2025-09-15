#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Point.hpp"
#include "Rect.hpp"
#include "Line.hpp"
#include "Circle.hpp"


using namespace std;

struct ParsedResult{
    string typeFig;
    vector<Point> points;
    int radius;
};

ParsedResult Parse_line(string input){
    ParsedResult result;
    stringstream ss(input);
    string token;

    if(ss >> token){
        result.typeFig = token;
    } else {
        result.typeFig = "error";
        return result;
    }

    if (result.typeFig == "circle"){
        string strX, strY, strRad; 
        ss >> strX >> strY >> strRad;

        Point center;
        center.SetX(stoi(strX));
        center.SetY(stoi(strY));
        result.radius = stoi(strRad);

        result.points.push_back(center);
        return result;
    }else if(result.typeFig == "point"){
        int x, y;
        string strX, strY;

        ss >> strX >> strY;

        Point point;
        point.SetX(stoi(strX));
        point.SetY(stoi(strY));
        result.points.push_back(point);

        return result;
    } else if(result.typeFig == "rect" or result.typeFig == "line"){
        string p1X, p1Y, p2X, p2Y;
        ss >> p1X >> p1Y >> p2X >> p2Y;

        Point p1, p2;
        p1.SetX(stoi(p1X));
        p1.SetY(stoi(p1Y));
        p2.SetX(stoi(p2X));
        p2.SetY(stoi(p2Y));

        result.points.push_back(p1);
        result.points.push_back(p2);
        return result;
    } else {
        return result;
    }
}

int main(){ 
    ifstream in("input.txt");
    // ofstream out("output.txt");

    if(in.is_open()){
        string str;
        while(getline(in, str)){
            ParsedResult result = Parse_line(str);
            if(result.typeFig == "point"){
                result.points[0].Draw();
            } else if(result.typeFig == "rect") {
                Rect rect(result.points[0], result.points[1]);
                rect.Draw();
            } else if(result.typeFig == "line"){
                Line line(result.points[0], result.points[1]);
                line.Draw();
            } else if(result.typeFig == "circle"){
                Circle circle(result.points[0], result.radius);
                circle.Draw();
            } else {
                cout << "problems with type of figure\n";

            }
        }
    }
    

    in.close();
    // out.close();

    return 0;
}