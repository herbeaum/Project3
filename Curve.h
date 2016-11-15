/* 
 * File:   curve.h
 * Author: mickael
 *
 * Created on November 14, 2016, 3:34 PM
 */

#ifndef CURVE_H
#define	CURVE_H
#include "Curvebase.h"
class Curve : public Curvebase{
public:
    Curve();
    Curve(const Curve& orig);
    Curve(int rev);
    virtual ~Curve();
    
    virtual double xp(double p);
    virtual double yp(double p);
    virtual double dxp(double p);
    virtual double dyp(double p);
private:

};

#endif	/* CURVE_H */

