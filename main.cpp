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
    //Line c(false, 5, 1, 4, 1);
        //Curve c(1);
	//double testS = 0;
	//cout << "For s = " << testS << endl;
	//cout << "x = " << c.x(1.0) << endl;
	//cout << "y = " << c.y(1.0) << endl;
	//cout << "integral = " << c.getLength() << endl;
    Line L1(false, 1, 1,4,1);
    Line L2(true, 4,1,3,1);
    Line L3(false,3,1,4,1);
    Line L4(true,1,1,3,1);
    Domain d(L1,L2,L3,L4);
    int m=4;
    int n=5;
    d.generating_grid(m,n);
    cout << "test"<<endl;
    Point P;
    for (int i =0; i<(n+1);i++){
        for (int j =0 ;j<(m+1);j++){
            P=d(i,j);
            P.print();
        }
        cout<< endl;
    }
    cout<< L1.getLength()<<endl;
    cout<< L2.getLength()<<endl;
    cout<< L3.getLength()<<endl;
    cout << L4.getLength()<<endl;
    return 0;
}

