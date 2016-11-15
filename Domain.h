/* 
 * File:   Domain.h
 * Author: mickael
 *
 * Created on November 7, 2016, 2:47 PM
 */

#ifndef DOMAIN_H
#define	DOMAIN_H
#include "Curvebase.h"
class Domain {
public:
    Domain();
    Domain(const Domain& orig);
    Domain(const Curvebase & c1,const Curvebase & c2,const Curvebase & c3,const Curvebase & c4);
    void generating_grid(int m, int n);
    virtual ~Domain();
private:
    Curvebase *sides[4];
    int m_,n_;
    double *X_, *Y_;
};

#endif	/* DOMAIN_H */

