/**
 * pointers recap
 *
 * Copyright (C) 2021, Tenzin Steel
 */
#include <cstdio>
#include <iostream>

struct Complex{
    double _real, _imaginary;

    Complex(double r, double i) : _real(r), _imaginary(i){
    }
    void dump(){
        printf("(%.3lf, %3lf)\n\n", _real, _imaginary);
    }
    void setReal(double r){
        _real = r;
    }
    void setImaginary(double i){
        _imaginary = i;
    }
};

void getComplex(Complex *cp){
    printf("enter complex number as <real>, <imaginary>\n");
    double r, i;
    scanf("%lf, %lf", &r, &i); // entering values into the address of our local varialbes
    cp->setReal(r);
    cp->setImaginary(i);
}

int main(){
    int i1 = 100; // name of var
    int *i1p = &i1; // ip1 pointer looking at i1 memory address

    printf("i1 = %d\ni1p = %p\n*i1p = %d\n\n", i1, i1p, *i1p);

    *i1p = 200;

    printf("i1 = %d\ni1p = %p\n*i1p = %d\n\n", i1, i1p, *i1p);

    Complex c1(0.500, 0.707);
    Complex *c1p = &c1;
    c1.dump(); // should print the same things
    c1p->dump(); // to access methods within class with a pointer, use "->"

    // read by passing pointer (note that this is not by reference)
    // remember we hae to make c2p pointet at something, 
    Complex *c2p = c1p;
    getComplex(c2p);
}