#include "color.h"

// a "definition" with an implementation
double Color:: _value(double v){
    if(v < 0){
        return 0;
    }
    if(v > 1){
        return 1;
    }
    return v;
}

// a "definition" with an implementation
Color:: Color() : _red(0), _green(0), _blue(0){
}

// a "definition" with an implementation
Color:: Color(double r, double g, double b) : _red(r), _green(g), _blue(b){
}
