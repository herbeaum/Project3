/* 
 * File:   Curvebase.cpp
 * Author: mickael
 * 
 * Created on November 7, 2016, 2:41 PM
 */

#include "Curvebase.h"

Curvebase::Curvebase(const Curvebase& orig) {
}

Curvebase::~Curvebase() {
}

double Curvebase::Newton(double (*f)(double),double (*df)(double),double x,double pres){
    double err, tol =pres, x1;
    int it, maxit=100;
    it =0;
    err =tol +1;
    while (err > tol && it < maxit ){
        x1 = x -f(x)/df(x);
        err =fabs(x1-x);
        x=x1; 
        it++;
    }
    if (err>tol ){
        std::cout << "error, no convergence"<<std::endl;
    }
    return x1;
}




double Curvebase::f(double q){
    return sqrt(dxp(q)*dxp(q)+dyp(q)+dyp(q));
}