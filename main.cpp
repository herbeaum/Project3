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
    Curve *c=new Curve(1);
    std::cout<<(c->x(0.1));

    return 0;
}

