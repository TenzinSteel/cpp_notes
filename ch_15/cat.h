/**
 * cat (derived calss) header
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#ifndef CAT_H_
#define CAT_H_

#include <string>
#include "animal.h"

class Cat : public Animal{
    private:
        std::string _sound = "meow";
    public:
        Cat(double);
        std::string sound() const;
};

#endif // CAT_H_