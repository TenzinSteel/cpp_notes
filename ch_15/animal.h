/**
 * animal (base calss) header
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_


class Animal{
    private:
        double _weight;

    public:
        Animal(double);
        double weight() const;
};

#endif // ANIMAL_H_