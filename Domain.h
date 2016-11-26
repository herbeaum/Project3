/* 
 * File:   Domain.h
 * Author: mickael/Raja
 *
 * Created on November 7, 2016, 2:47 PM
 */

#ifndef DOMAIN_H
#define	DOMAIN_H
#include "Curvebase.h"
#include "Point.h"
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>

class Domain {
    
public:
    //////////////////
    // Constructors //
    //////////////////
    /*
    * A constructor taking the four Curvebase 
    */
    
    Domain(Curvebase & c1, Curvebase & c2, Curvebase & c3, Curvebase & c4);
    /*
     * Copy constructor
     */
    Domain(const Domain& orig);
    /*
     * Move constructor
     */
    Domain(Domain && d) noexcept;
    
    
    
    //////////////////
    //  Destructor  //
    //////////////////
    ~Domain();
     
    
    
    
    //////////////////////////
    // Overloaded operators //
    //////////////////////////
    
    /*
    * Overloads the = operator for matrices
    */
    Domain &operator=(const Domain &d);
    /*
    * Overloads the = operator for matrices (like the move constructor)
    */
    Domain &operator=(Domain &&d) noexcept;
    /*
    * Overloads the () operator for Domain to access
    * the element at line i and column j of the grid
    */
    Point operator()(int i, int j) const;
    
    ////////////////////////////////
    // Matrix specific operations //
    ////////////////////////////////
    /*
     * save grid coordinates in csv file called str
     */
    void print(std::string const &str) const;
    /*
     * save grid coordinates in binary file
     */
    void save() const;
    /*
     *Compute coordinates for the grid points
     */
    void generating_grid(int m, int n);
    
private:
    /*
     * Vectors to store the grid coordinates
     */ 
    double *X_, *Y_;
    /*
     *Array of the 4 curvebases of the domain
     */
    Curvebase *sides[4];
    /*
     * Number of points in the grid
     */
    int m_, n_;
    /*
     *private variables to avoid unnecessary calculations
     */
    double x00,x01,x20,x21,y00,y01,y20,y21;
    /*
     * Check the consistency of the domain (We check the 4 corners of the domains)
     */
    bool check_consistency();
    /*
     *Linear interpolation
     */
    double phi1(double p)const;
    double phi2(double p)const;
    
    bool check(double a, double b, double tol);

};

#endif	/* DOMAIN_H */

