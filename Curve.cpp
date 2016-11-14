/* 
 * File:   curve.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:34 PM
 */

#include "Curve.h"
using namespace std;
Curve::Curve() {
}

Curve::Curve(const Curve& orig) {
}

Curve::Curve(double a,double b, double pmin,double pmax,int rev){
    this->a=a;
    this->b=b;
    this->pmin=pmin;
    this->pmax=pmax;
    this->rev=rev;
    length=integrate(f,a,b);
}


Curve::~Curve() {
}


virtual double Curve::xp(double p){
    return p;
}

virtual double Line::dxp(double p){
    return 1;
}


virtual double Line::yp(double p){
    if (p>=-10 && p<-3){
        return 1/(2*(1+exp(-3*(p+6))));
    }else if (p>=-3 && p<=5){
        return 1/(2*(1+exp(3*p)));
    }else {
        throw invalid_argument(" p out of bounds");
    }
}

virtual double Line::dyp(double p){
     if (p>=-10 && p<-3){
        return (3*exp(-3*(p+6)))/(2*(1+exp(-3*(p+6))));
    }else if (p>=-3 && p<=5){
        return -3*exp(3*p)/(2*(1+exp(3*p)));
    }else {
        throw invalid_argument(" p out of bounds");
    }
}