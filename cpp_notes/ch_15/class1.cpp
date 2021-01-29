/**
 * check inheritance
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include "cat.h"
#include "dog.h"

int main(){
    Cat c1(10);
    printf("c1.weight() = %.1lf, c1.sound() = %s\n", 
    c1.weight(), c1.sound());

    Dog d1(20);
    printf("d1.weight() = %.1lf, d1.sound() = %s\n", 
    d1.weight(), d1.sound());
}