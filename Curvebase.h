/* 
 * File:   Curvebase.h
 * Author: mickael
 *
 * Created on November 7, 2016, 2:41 PM
 */

#ifndef CURVEBASE_H
#define	CURVEBASE_H

// C++ libraries
#include <stdexcept>
#include <iostream>

// C libraries
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

class Curvebase {

protected:
	// Inheritable attrubutes
	double a;
	double b;
	int rev;
	double length;

	// Parametrized coordinates and their derivatives
	virtual double xp(double p) = 0;
	virtual double yp(double p) = 0;
	virtual double dxp(double p) = 0;
	virtual double dyp(double p) = 0;

	// The integration function and the function
	// to be integrated
	double f(double q);
	double integrate(double a, double b);

public:

	// Constructors
	Curvebase() : a(0.0), b(0.0), rev(0.0), length(0.0) {};
	Curvebase(const Curvebase& orig);

	// Destructor
	virtual ~Curvebase();

	// Coordinates in the original domain
	double x(double s);
	double y(double s);

private:
	// Internal functions
	double integrate(double a, double b, double tol);
	double Newton(double s, double x, double pres);
	double iFunc(double a, double b);
	double i2Func(double a, double b);
	double f_p(double p, double s);

};

#endif	/* CURVEBASE_H */
