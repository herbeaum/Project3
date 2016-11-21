/* 
 * File:   curve.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:34 PM
 */

#include "Curve.h"
using namespace std;



Curve::Curve(const Curve& orig) {
    if (this == &orig) {
        throw std::invalid_argument("ERROR: Copy constructor on itself");
    }
    a=orig.a;
    b=orig.b;
    rev=orig.rev;
    length=orig.length;
}

Curve::Curve(double a, double b,int rev) {
    this->a = a;
    this->b = b;
    this->rev = rev;
    length = integrate(a, b);
}

Curve::~Curve() {
}

double Curve::xp(double p) {
    return p;
}

double Curve::dxp(double p) {
    return 1;
}

double Curve::yp(double p) {
    if (p<-3) {
        return 1 / (2 * (1 + exp(-3 * (p + 6))));
    } else if (p >= -3 ) {
        return 1 / (2 * (1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}

double Curve::dyp(double p) {
    if ( p<-3) {
        return (3 * exp(-3 * (p + 6))) / (2 * (1 + exp(-3 * (p + 6)))*(1 + exp(-3 * (p + 6))));
    } else if (p >= -3) {
        return -3 * exp(3 * p) / ((2 * (1 + exp(3 * p)))*(1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}