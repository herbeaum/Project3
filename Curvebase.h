/* 
 * File:   Curvebase.h
 * Author: mickael
 *
 * Created on November 7, 2016, 2:41 PM
 */

#ifndef CURVEBASE_H
#define	CURVEBASE_H

class Curvebase {
protected:
    double pmin;
    double pmax;
    double a;
    double b;
    int rev;
    double length;
    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double f(double q);
    double integrate(double (*f)(double), double a, double b);
public:
    Curvebase():pmin(0.0),pmax(0.0),a(0.0),b(0.0),rev(0.0),length(0.0){};
    Curvebase(const Curvebase& orig);
    double x(double s);
    double y(double s);
    virtual ~Curvebase();
private:
    double integrate(double (*f)(double), double a, double b, double tol);
    double Newton(double (*f)(double),double (*df)(double),double x,double pres);
    double iFunc(double (*f)(double), double a, double b);
    double i2Func(double (*f)(double), double a, double b);

};

#endif	/* CURVEBASE_H */

