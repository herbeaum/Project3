/* 
 * File:   Domain.cpp
 * Author: mickael
 * 
 * Created on November 7, 2016, 2:47 PM
 */
#include <cstdio>
#include <iostream>
#include <string.h>
#include "Domain.h"
using namespace std;

Domain::Domain(Curvebase & c1, Curvebase & c2, Curvebase & c3, Curvebase & c4) {
    sides[0] = &c1;
    sides[1] = &c2;
    sides[2] = &c3;
    sides[3] = &c4;
    m_ = 0;
    n_ = 0;

    x00 = sides[0]->x(0);
    x01 = sides[0]->x(1);
    x20 = sides[2]->x(0);
    x21 = sides[2]->x(1);
    y00 = sides[0]->y(0);
    y01 = sides[0]->y(1);
    y20 = sides[2]->y(0);
    y21 = sides[2]->y(1);
    if (!check_consistency()) {
        cout<< "Domain invalid (check continuity)"<<endl;
        m_ = n_ = 0;
        X_ = Y_ = NULL;
        sides[0] = sides[1] = sides[2] = sides[3] = NULL;
    }
}

Domain::Domain(const Domain& orig) : m_(orig.m_), n_(orig.n_), X_(NULL), Y_(NULL) {
    if (this == &orig) {
        throw std::invalid_argument("ERROR: Copy constructor on itself");
    }
    if (m_ > 0) {
        x00 = orig.x00, x01 = orig.x01, x20 = orig.x20, x21 = orig.x21;
        y00 = orig.y00, y01 = orig.y01, y20 = orig.x20, y21 = orig.x21;
        X_ = new double[(m_ + 1)*(n_ + 1)];
        Y_ = new double[(m_ + 1)*(n_ + 1)];
        memcpy(X_, orig.X_, (m_ + 1)*(n_ + 1) * sizeof (double));
        memcpy(Y_, orig.Y_, (m_ + 1)*(n_ + 1) * sizeof (double));
        for (int i = 0; i < 4; i++) {
            sides[i] = orig.sides[i];
        }
    }
}

Domain::Domain(Domain&& d) noexcept {
    m_ = (d.m_), n_ = (d.n_), X_ = (d.X_), Y_ = (d.Y_);
    x00 = d.x00, x01 = d.x01, x20 = d.x20, x21 = d.x21;
    y00 = d.y00, y01 = d.y01, y20 = d.x20, y21 = d.x21;
    for (int i = 0; i < 4; i++) {
        sides[i] = d.sides[i];
    }
    d.m_ = 0;
    d.n_ = 0;
    d.X_ = NULL;
    d.Y_ = NULL;
}

Domain::~Domain() {
    if (m_ > 0) {
        delete []X_;
        delete []Y_;
    }
}

void Domain::generating_grid(int m, int n) {
    if (m <= 0 || n <= 0) {
        throw invalid_argument("m or n can't be negative or equal to zero");
    }
    if (sides[0]==NULL){
        throw invalid_argument("Domain invalid (We can't generate the grid)");
    }
    if (m_ > 0) { //there exists already a grid
        delete [] X_;
        delete [] Y_;
    }
    m_ = m;
    n_ = n;
    X_ = new double[(m_ + 1)*(n_ + 1)];
    Y_ = new double[(m_ + 1)*(n_ + 1)];

    double h1 = 1.0 / n_;
    double h2 = 1.0 / m_;
    //Fill x_ and Y_
    for (int i = 0; i <= n_; i++) {
        for (int j = 0; j <= m_; j++) {
            X_[j + i * (m + 1)] = phi1(i * h1) * sides[3]->x(j * h2) //phi1(e1)x(0,e2)
                    + phi2(i * h1) * sides[1]->x(j * h2)//phi2(e1)x(1,e2)
                    + phi1(j * h2) * sides[0]->x(i * h1)//phi1(e2)x(e1,0)
                    + phi2(j * h2) * sides[2]->x(i * h1)//phi2(e2)x(e1,1)
                    - phi1(i * h1) * phi1(j * h2) * x00//phi1(e1)phi1(e2)x(0,0)
                    - phi2(i * h1) * phi1(j * h2) * x01//phi2(e1)phi1(e2)x(1,0)
                    - phi1(i * h1) * phi2(j * h2) * x20//phi1(e1)phi2(e2)x(0,1)
                    - phi2(i * h1) * phi2(j * h2) * x21; //phi2(e1)phi2(e1)x(1,1)
            Y_[j + i * (m + 1)] = phi1(i * h1) * sides[3]->y(j * h2)
                    + phi2(i * h1) * sides[1]->y(j * h2)
                    + phi1(j * h2) * sides[0]->y(i * h1)
                    + phi2(j * h2) * sides[2]->y(i * h1)
                    - phi1(i * h1) * phi1(j * h2) * y00
                    - phi2(i * h1) * phi1(j * h2) * y01
                    - phi1(i * h1) * phi2(j * h2) * y20
                    - phi2(i * h1) * phi2(j * h2) * y21;

        }
    }

}
bool Domain::check(double a, double b, double tol){
    return (std::abs(a-b)<tol);
}

bool Domain::check_consistency() {
    bool check_x = check(sides[0]->x(0), sides[3]->x(0), 1e-5)
            && check(sides[0]->x(1), sides[1]->x(1), 1e-5)
            && check(sides[1]->x(1), sides[2]->x(1), 1e-5)
            && check(sides[2]->x(0), sides[3]->x(0), 1e-5);
    bool check_y = check(sides[0]->y(0), sides[3]->y(0), 1e-5)
            && check(sides[0]->y(0), sides[1]->y(0), 1e-5)
            && check(sides[1]->y(1), sides[2]->y(1), 1e-5)
            && check(sides[2]->y(1), sides[3]->y(1), 1e-5);
    return (check_x && check_y);
}

double Domain::phi1(double p)const {
    return (1 - p);
}

double Domain::phi2(double p)const {
    return p;
}

Domain & Domain::operator=(const Domain& d) {
    if (this == &d) {
        throw std::invalid_argument("ERROR: Copy operator on itself");
    }
    if (m_ == d.m_ && n_ == d.n_) {
        memcpy(X_, d.X_, (m_ + 1)*(n_ + 1) * sizeof (double));
        memcpy(Y_, d.Y_, (m_ + 1)*(n_ + 1) * sizeof (double));
    } else {
        if (m_ > 0) {
            delete []X_;
            delete []Y_;
            X_ = Y_ = NULL;
        }
        m_ = d.m_;
        n_ = d.n_;
        if (m_ > 0) {
            X_ = new double[(m_ + 1)*(n_ + 1)];
            Y_ = new double[(m_ + 1)*(n_ + 1)];
            memcpy(X_, d.X_, (m_ + 1)*(n_ + 1) * sizeof (double));
            memcpy(Y_, d.Y_, (m_ + 1)*(n_ + 1) * sizeof (double));
        }
    }
    x00 = d.x00, x01 = d.x01, x20 = d.x20, x21 = d.x21;
    y00 = d.y00, y01 = d.y01, y20 = d.x20, y21 = d.x21;
    for (int i = 0; i < 4; i++) {
        sides[i] = d.sides[i];
    }

}

Domain & Domain::operator=(Domain&& d) noexcept {
    x00 = d.x00, x01 = d.x01, x20 = d.x20, x21 = d.x21;
    y00 = d.y00, y01 = d.y01, y20 = d.x20, y21 = d.x21;
    if (m_ == d.m_ && n_ == d.n_) {
        X_ = d.X_;
        Y_ = d.Y_;
    } else {
        if (m_ > 0) {
            delete []X_;
            delete []Y_;
            X_ = Y_ = NULL;
        }
        m_ = d.m_;
        n_ = d.n_;
        if (m_ > 0) {
            X_ = d.X_;
            Y_ = d.Y_;
        }
    }
    d.X_ = NULL;
    d.Y_ = NULL;
    d.m_ = 0;
    d.n_ = 0;
    for (int i = 0; i < 4; i++) {
        sides[i] = d.sides[i];
    }
}

Point Domain::operator()(int i, int j) const {
    if (i < 0 || i > n_ || j < 0 || j > m_) {
        throw invalid_argument(" i or j out of bounds");
    }
    int ind = j + i * (m_ + 1);
    return Point(X_[ind], Y_[ind]);
}

void Domain::print(const std::string& str) const {
    ofstream file(str.c_str(), ios::out);
    if (file) {
        file << "X;Y;" << endl;
        for (int i = 0; i < (n_ + 1)*(m_ + 1); i++) {
            file << X_[i] << ";" << Y_[i] << ";" << endl;
        }
        file.close();
    } else {
        cerr << "Impossible to open the file !" << endl;
    }
}

void Domain::save() const {
    FILE* p = fopen("domain.bin", "wb");
    if (p == NULL) {
        cerr << "Cannot create domain.bin file!" << endl;
    }
    char sizeOfInt = (char) sizeof (int);
    char sizeOfDouble = (char) sizeof (double);
    int m = m_ + 1;
    int n = n_ + 1;
    fwrite(&sizeOfInt, 1, 1, p);
    fwrite(&sizeOfDouble, 1, 1, p);
    fwrite(&m, sizeOfInt, 1, p);
    fwrite(&n, sizeOfInt, 1, p);
    fwrite(X_, sizeOfDouble, m * n, p);
    fwrite(Y_, sizeOfDouble, m * n, p);
    fclose(p);
}
