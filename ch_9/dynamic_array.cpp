/**
 * introduction to dynamic arrays using pointers
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <cstdio>
#include <random>

using namespace std;

// good practce to create constants this way
#define SIZE 10

// function to fill array with randomn number
void populate(int array[], int size){
    for (int i = 0; i < size; i++){
        array[i] = rand() % 1000;
    }
}

int main(){
    // this sets a pointer to the first elemtent in the array of 10
    // the "new" basaicly creates the array
    int *myArray = new int[SIZE];

    populate(myArray, SIZE);
    for (int i  = 0; i < SIZE; i++){
        // make comma sepparated output
        if (i > 0){
            printf(", ");
        }
        printf("%d", myArray[i]); // myArray[i] is equiv to *(myArray + 1)
    }
    // any time you do a "new" you have to do a "delete" to avoid memory leaks.
    // you must include the "[]" or else it only deletes the first element.
delete [] myArray;
}

// output: 41, 467, 334, 500, 169, 724, 478, 358, 962, 464


