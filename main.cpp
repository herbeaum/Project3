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
/*
 * 
 */
int main(int argc, char** argv) {
//    Line c(false, 5, 1, 4, 1);
    Curve c(1);
	double testS = 0;
	cout << "For s = " << testS << endl;
	cout << "x = " << c.x(0) << endl;
	cout << "y = " << c.y(0) << endl;
//	cout << "integral = " << c.getLength() << endl;

    return 0;
}

