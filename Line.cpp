/* 
 * File:   Line.cpp
 * Author: mickael
 * 
 * Created on November 14, 2016, 3:15 PM
 */

// Header file
#include "Line.h"

// Open the std namespace
using namespace std;

// Constructors

// Ordinary constructor
Line::Line(bool vert,double coord,double a,double b,int rev){
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
    vertical=vert;
    x1=coord;
    length=integrate(a,b);
}

// Copy constructor
Line::Line(const Line& orig) {
    if (this == &orig) {
        throw invalid_argument("ERROR: Copy constructor on itself");
    }
    a=orig.a;
    b=orig.b;
    rev=orig.rev;
    x1=orig.x1;
    vertical=orig.vertical;
    length=orig.length;
}

// Destructor

Line::~Line() {
}

// Parametrized coordinates and their derivatives

// Function taking a parameter p and returning
// the corresponding x coordinate according to
// the parametrization
double Line::xp(double p){
    if (vertical){
        return x1;
    }else{
        return p;
    }
}

// Function representing the derivative of xp
double Line::dxp(double p){
    if (vertical){
        return 0;
    }else{
        return 1;
    }
}

// Function taking a parameter p and returning
// the corresponding y coordinate according to
// the parametrization
double Line::yp(double p){
    if (vertical){
        return p;
    }else{
        return x1;
    }
}

// Function representing the derivative of yp
double Line::dyp(double p){
    if (vertical){
        return 1;
    }else{
        return 0;
    }
}
