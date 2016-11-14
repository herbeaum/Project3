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

double Curvebase::integrate(double (*f)(double), double a, double b) {
	integrate(f, a, b, 1e-8);
}

double Curvebase::integrate(double (*f)(double), double a, double b, double tol) {
	// Arguments check
	if (tol <= 0) {
		throw invalid_argument("The given tolerance value is not strictly positive!");
	}

	// Variable declarations/initializations
	int nodeCount = 1;
	bool done = false;
	bool* doneChildren = (bool*)calloc(1, sizeof(bool));
	bool* doneChildrenNext;
	double sum = 0;
	double interval = b - a;

	// Main loop
	while (!done) {
		done = true;
		doneChildrenNext = (bool*)calloc(nodeCount << 1, sizeof(bool));
		double subInterval = interval / nodeCount;

		// Inner loop
		for (int i = 0 ; i < nodeCount ; i++) {
			if (!doneChildren[i]) {
				// Inreval is not already done
				// from and to correspond to the bounds of the subinterval
				double from = a + i * subInterval;
				double to = from + subInterval;
				double i1 = iFunc(f, from, to);
				double i2 = i2Func(f, from, to);
				if (abs(i1 - i2) >= 15 * tol) {
					// Need to go to next iteration to split this interval
					// in two and compute i1 and i2 for each subinterval,
					// so mark done as false
					done = false;
				} else {
					// Mark left child and right child as done in next
					// boolean array and add i2 to the sum
					int leftChild = i << 1;
					doneChildrenNext[leftChild] = true;
					doneChildrenNext[leftChild + 1] = true;
					sum += i2;
				}
			} else {
				// Interval already done, so mark its children as done
				// as well
				int leftChild = i << 1;
				doneChildrenNext[leftChild] = true;
				doneChildrenNext[leftChild + 1] = true;
			}
		}

		// Decrease the tolerance value by half, free the no longer needed
		// memory for the current iteration, set the next boolean array as
		// the current boolean array, and finally double the number of
		// nodes/children for the next iteration
		tol /= 2;
		free(doneChildren);
		doneChildren = doneChildrenNext;
		nodeCount <<= 1;
	}
	
	// Free allocated memory
	free(doneChildren);

	// Return the result
	return sum;

}

// A function that takes two doubles and returns
// some sort of weighted average of the function
// over the interval between these two doubles
double Curvebase::iFunc(double (*f)(double), double a, double b) {
	return (b - a) * (f(a) + 4 * f((a + b) / 2) + f(b)) / 6;
}

// A function that takes two doubles and returns
// sum of the results of calling the function iFunc
// over the two halves of the interval between
// these two doubles
double Curvebase::i2Func(double (*f)(double), double a, double b) {
	double gamma = (a + b) / 2;
	return iFunc(f, a, gamma) + iFunc(f, gamma, b);
}

double Curvebase::f(double q){
    return sqrt(dxp(q)*dxp(q)+dyp(q)+dyp(q));
}
