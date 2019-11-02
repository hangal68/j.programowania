#ifndef _prosta_hpp_
#define _prosta_hpp_
//#include "parabola.hpp"
#include <iostream>

class Prosta {
    float a,b;
    static int counter;
public:
    Prosta(float aa = 0, float ab = 0): a(aa), b(ab) { counter ++; }
    ~Prosta() {counter --;}
    void policz_styczna(Point point, Parabola parabola);
    void info();
};

#endif