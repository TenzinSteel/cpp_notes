/**
 * error handling from command line input
 * fib sequence also
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>

#define MAX 10

// naive recursion
// O(n^2) time complexity because it doubles
// O(n) space complexity
uint64_t fib1(int n){
    // base case, don't forget this or you will get an infinite loop
    if(n < 2){
        return n;
    }
    return fib1(n - 1) + fib1(n -2);
}

void error(const char *cmd){
    // this prints to stderr (error stream) and not stdout (standard stream)
    fprintf(stderr, "Usage: %s <+vs integer>\n", argv[0]);
    // anything other than exit(0) indicates failure
    // this can exit program from anywhere
    exit(1); 
}

// note how command line arguments are detected
int main(int argc, char *argv[]){
    int n;

    // sscanf converts string from argv[1] into an integer and puts it into n
    // pass address in for n so we can actualy store the value in
    if(argc < || scanf(argv[1], "%d", &n) == 0 || n < 0 || n > MAX){
        error(argv[0])
    }
    printf("fib1(%d) = %lu\n", n, fib1(n));
}