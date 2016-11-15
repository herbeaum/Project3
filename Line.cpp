/* 
 * File:   Line.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:15 PM
 */

#include "Line.h"

Line::Line() {
}

Line::Line(bool vert,double coord,double a,double b,int rev){
    vertical=vert;
    x=coord;
    this->a=a;
    this->b=b;
    this->rev=rev;
    length=integrate(a,b);
}

Line::Line(const Line& orig) {
}

Line::~Line() {
}

double Line::xp(double p){
    if (vertical){
        return x;
    }else{
        return p;
    }
}

double Line::dxp(double p){
    if (vertical){
        return 0;
    }else{
        return 1;
    }
}


double Line::yp(double p){
    if (vertical){
        return p;
    }else{
        return x;
    }
}

double Line::dyp(double p){
    if (vertical){
        return 1;
    }else{
        return 0;
    }
}