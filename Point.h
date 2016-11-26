/* 
 * File:   Point.h
 * Author: mickael/Raja
 *
 * Created on November 19, 2016, 10:27 AM
 */

#ifndef POINT_H
#define	POINT_H
#include <stdexcept>
#include <iostream>

class Point {
public:
    /*
     *Default constructor
     */
    Point() : X(0.0), Y(0.0) {
    };
    /*
     *Constructor which takes 2 double as coordinates
     */
    Point(double X, double Y);
    /*
     *Copy constructor
     */
    Point(const Point& orig);
     ~Point();

    inline double getX() const {
        return X;
    };

    double getY() const {
        return Y;
    };

private:
    double X;
    double Y;
};

#endif	/* POINT_H */

