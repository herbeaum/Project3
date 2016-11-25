/* 
 * File:   main.cpp
 * Author: mickael
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
/*
 * 
 */
int main(int argc, char** argv) {
    Curve c1(-10,5,1);
    Line L2(true, 5,0,3,1);
    Line L3(false,3,-10,5,1);
    Line L4(true,-10,0,3,1);
    Domain d(c1,L2,L3,L4);
    int m=25;
    int n=30;
    d.generating_grid(m,n);
    d.print("test.csv");
	d.save();
    return 0;
}

