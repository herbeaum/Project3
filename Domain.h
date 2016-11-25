/* 
 * File:   Domain.h
 * Author: mickael
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
    
    Domain(const Domain& orig);
    Domain(Curvebase & c1, Curvebase & c2, Curvebase & c3, Curvebase & c4);
    Domain(Domain && d) noexcept;
    void generating_grid(int m, int n);
    ~Domain();
    Domain &operator=(const Domain &d);
    Domain &operator=(Domain &&d) noexcept;
    Point operator()(int i, int j) const;
    void print(std::string const &str) const;
	void save() const;
    
private:
    
    double *X_, *Y_;
    Curvebase *sides[4];
    int m_, n_;

    bool check_consistency()const;
    double phi1(double p)const;
    double phi2(double p)const;

};

#endif	/* DOMAIN_H */

