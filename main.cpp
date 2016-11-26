/* 
 * File:   main.cpp
 * Author: mickael/Raja
 *
 * Created on November 14, 2016, 2:07 PM
 */

#include <cstdlib>

using namespace std;
#include "Curvebase.h"
#include "Curve.h"
#include "Line.h"
#include "Domain.h"
#include "Point.h"

int main(int argc, char** argv) {
    /*
     *Creation of the domain
     */
    Curve c1(-10,5,1);
    Line L2(true, 5,0,3,1);
    Line L3(false,3,-10,5,1);
    Line L4(true,-10,0,3,1);
    Domain d(c1,L2,L3,L4);
    /*
     *Creation of the grid
     */
    int m=50;
    int n=20;
    d.generating_grid(m,n);
    /*
     *Save the grid in binary file
     */
    d.save();
    return 0;
}

