/* 
 * File:   Line.h
 * Author: mickael
 *
 * Created on November 14, 2016, 3:15 PM
 */

#ifndef LINE_H
#define	LINE_H
#include "Curvebase.h"
class Line: public Curvebase{
public:
    Line();
    Line(bool vert,double coord,double a,double b, double pmin,double pmax,int rev);
    Line(const Line& orig);
    virtual ~Line();
    
    virtual double xp(double p);
    virtual double yp(double p);
    virtual double dxp(double p);
    virtual double dyp(double p);
private:
    bool vertical;
    double x;

};

#endif	/* LINE_H */

