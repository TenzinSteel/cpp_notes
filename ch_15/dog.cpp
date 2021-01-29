/**
 * dog (derived class) implamentation
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include "cat.h"

Dog:: Dog(double w) : Animal(w){
}

std::string Dog:: sound() const{
    return _sound
}