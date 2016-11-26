/* 
 * File:   Point.cpp
 * Author: mickael
 * 
 * Created on November 19, 2016, 10:27 AM
 */

#include "Point.h"

using namespace std;

Point::Point(const Point& orig) {
    if (this == &orig) {
        throw invalid_argument("You can't use the copy constructor on itself");
    }
    X = orig.X;
    Y = orig.Y;
}

Point::Point(double X, double Y) {
    this->X = X;
    this->Y = Y;
}

Point::~Point() {
}

