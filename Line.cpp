/* 
 * File:   Line.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:15 PM
 */

#include "Line.h"



Line::Line(bool vert,double coord,double a,double b,int rev){
    if (rev != 0 && rev !=1){
        throw std::invalid_argument("ERROR: Invalid argument for rev \n rev=1 clockwise direction and 0 otherwise "); 
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
    vertical=vert;
    x1=coord;
    length=integrate(a,b);
}

Line::Line(const Line& orig) {
    if (this == &orig) {
        throw std::invalid_argument("ERROR: Copy constructor on itself");
    }
    a=orig.a;
    b=orig.b;
    rev=orig.rev;
    x1=orig.x1;
    vertical=orig.vertical;
    length=orig.length;
}

Line::~Line() {
}

double Line::xp(double p){
    if (vertical){
        return x1;
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
        return x1;
    }
}

double Line::dyp(double p){
    if (vertical){
        return 1;
    }else{
        return 0;
    }
}