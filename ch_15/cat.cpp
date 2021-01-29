/**
 * cat (derived class) implamentation
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include "cat.h"

Cat:: Cat(double w) : Animal(w){
}

std::string Cat:: sound() const{
    return _sound
}