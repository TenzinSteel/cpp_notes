/**
 * color declarations
 *
 * Copyright (C) 2021, Tenzin Steel
 */

// this is a "header file" with nothing except declarations in it.

class Color{
    private:
        double _red, _green, _blue;
        // all "declarations" with no implementation
        double _value(double v);
    public:
        Color();
        Color(double, double, double);
};