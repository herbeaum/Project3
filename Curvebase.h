/* 
 * File:   Curvebase.h
 * Author: mickael
 *
 * Created on November 7, 2016, 2:41 PM
 */

#ifndef CURVEBASE_H
#define	CURVEBASE_H
#include <stdexcept>
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Curvebase {
protected:
    double a;
    double b;
    int rev;
    double length;
    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double f(double q);
    double integrate( double a, double b);
public:
    Curvebase():a(0.0),b(0.0),rev(0.0),length(0.0){};
    Curvebase(const Curvebase& orig);
    double x(double s);
    double y(double s);
    virtual ~Curvebase();
	/**/
	double getLength() {return length;}
	/**/
private:
    double integrate( double a, double b, double tol);
    double Newton(double s,double x,double pres);
    double iFunc( double a, double b);
    double i2Func( double a, double b);
    double f_p(double p, double s);

};

#endif	/* CURVEBASE_H */

