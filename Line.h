/* 
 * File:   Line.h
 * Author: mickael
 *
 * Created on November 14, 2016, 3:15 PM
 */

#ifndef LINE_H
#define	LINE_H

// Header file of inherited class
#include "Curvebase.h"

// Class skeleton
class Line: public Curvebase {

public:

	// Constructors
	Line(bool vert,double coord,double a,double b,int rev);
	Line(const Line& orig);

	// Destructor
	virtual ~Line();

	// Parametrized coordinates and their derivatives
	virtual double xp(double p);
	virtual double yp(double p);
	virtual double dxp(double p);
	virtual double dyp(double p);

private:
	// Internal variables
	bool vertical;
	double x1;

};

#endif	/* LINE_H */
