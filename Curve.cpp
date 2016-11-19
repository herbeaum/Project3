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

Curve::Curve(int rev) {
    this->a = -10;
    this->b = 5;
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
    if (p >= -10 && p<-3) {
        return 1 / (2 * (1 + exp(-3 * (p + 6))));
    } else if (p >= -3 && p <= 5) {
        return 1 / (2 * (1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}

double Curve::dyp(double p) {
    if (p >= -10 && p<-3) {
        return (3 * exp(-3 * (p + 6))) / (2 * (1 + exp(-3 * (p + 6)))*(1 + exp(-3 * (p + 6))));
    } else if (p >= -3 && p <= 5) {
        return -3 * exp(3 * p) / ((2 * (1 + exp(3 * p)))*(1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}