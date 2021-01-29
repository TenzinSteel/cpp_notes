/**
 * typedef example
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef const char *String;

int main(){
    String tag = "example";
    printf("%s\n",tag);
}