/* 
 * File:   Point.h
 * Author: mickael
 *
 * Created on November 19, 2016, 10:27 AM
 */

#ifndef POINT_H
#define	POINT_H
#include <stdexcept>
#include <iostream>

class Point {
public:

    Point() : X(0.0), Y(0.0) {
    };
    Point(double X, double Y);
    Point(const Point& orig);
    virtual ~Point();

    inline double getX() const {
        return X;
    };

    double getY() const {
        return Y;
    };
    void print();
private:
    double X;
    double Y;
};

#endif	/* POINT_H */

