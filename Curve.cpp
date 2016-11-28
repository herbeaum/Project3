/* 
 * File:   curve.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:34 PM
 */

// Header file
#include "Curve.h"

// Open the std namespace
using namespace std;

// Constructors

// Ordinary constructor
Curve::Curve(double a, double b,int rev) {
    if (rev != 0 && rev !=1){
        throw invalid_argument("ERROR: Invalid argument for rev \n rev=1 clockwise direction and 0 otherwise "); 
    }
    this->rev=rev;
    if (a>b){
        this->rev=1;
        this->a=b;
        this->b=a;
    }else{
        this->a=a;
        this->b=b;
    }
    length = integrate(a, b);
}

// Copy constructor
Curve::Curve(const Curve& orig) {
    if (this == &orig) {
        throw invalid_argument("ERROR: Copy constructor on itself");
    }
    a=orig.a;
    b=orig.b;
    rev=orig.rev;
    length=orig.length;
}

// Destructor

Curve::~Curve() {
}

// Parametrized coordinates and their derivatives

// Function taking a parameter p and returning
// the corresponding x coordinate according to
// the parametrization
double Curve::xp(double p) {
    return p;
}

// Function representing the derivative of xp
double Curve::dxp(double p) {
    return 1;
}

// Function taking a parameter p and returning
// the corresponding y coordinate according to
// the parametrization
double Curve::yp(double p) {
    if (p<-3) {
        return 1 / (2 * (1 + exp(-3 * (p + 6))));
    } else if (p >= -3 ) {
        return 1 / (2 * (1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}

// Function representing the derivative of yp
double Curve::dyp(double p) {
    if ( p<-3) {
        return (3 * exp(-3 * (p + 6))) / (2 * (1 + exp(-3 * (p + 6)))*(1 + exp(-3 * (p + 6))));
    } else if (p >= -3) {
        return -3 * exp(3 * p) / ((2 * (1 + exp(3 * p)))*(1 + exp(3 * p)));
    } else {
        throw invalid_argument("p out of bounds");
    }
}