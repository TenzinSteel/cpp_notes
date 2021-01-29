/**
 * dog (derived calss) header
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#ifndef DOG_H_
#define DOG_H_

#include <string>
#include "animal.h"

class Dog : public Animal{
    private:
        std::string _sound = "woof";
    public:
        Dog(double);
        std::string sound() const;
};

#endif // DOG_H_