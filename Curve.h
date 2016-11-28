/* 
 * File:   curve.h
 * Author: mickael
 *
 * Created on November 14, 2016, 3:34 PM
 */

#ifndef CURVE_H
#define	CURVE_H

// Header file of inherited class
#include "Curvebase.h"

// Class skeleton
class Curve : public Curvebase{

public:

	// Constructors
	Curve();
	Curve(const Curve& orig);
	Curve(double a, double b, int rev = 0);

	// Destructor
	virtual ~Curve();

	// Parametrized coordinates and their derivatives
	virtual double xp(double p);
	virtual double yp(double p);
	virtual double dxp(double p);
	virtual double dyp(double p);

private:

};

#endif	/* CURVE_H */
