/**
 * introduction to pointers
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    
    // basic pointer use
    int value1 = 100;
    int *key = &value1;
    int value2 = *key;

    printf("value1 = %d, key = %p, value2 = %d\n", value1, key, value2);
    // value1 = 100
    // value2 = 100

    // this changes the value of value1 to 200 for some reason
    *key = 200;

    printf("new value1 = %d, new value2 = %d", value1, value2);

    swap(&value1, &value2);

    printf("value1 = %d, value2 = %d", value1, value2);

}

// swap by pointer is better than swap by reference 
void swap(int *key1, int *key2){
    int c = *key1;
    *key1 = *key2;
    *key2 = c;
}

  