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

// using memoization
// keyword "auto" automatically deduces the type, still static typing
auto vals = new uint64_t[MAX](); // the () at the end initializes values to 0

// O(n) time complexity
// O(n) space complexity
uint64_t fib2(int n){
    // always check for base case
    if(n < 2){
        return n;
    }
    // use cache
    if (vals[n] == 0){
        // this expensive step runs only in case of cache miss
        vals[n] = fib2(n -1) + fib2(n - 2);
    }
    return vals[n];
}

void error(const char *cmd){
    // this prints to stderr (error stream) and not stdout (standard stream)
    printf(stderr, "Usage: %s <+vs integer>\n", cmd);
    // anything other than exit(0) indicates failure
    // this can exit program from anywhere
    exit(1); 
}

// note how command line arguments are detected
int main(int argc, char *argv[]){
    int n;
    // sscanf converts string from argv[1] into an integer and puts it into n
    // pass address in for n so we can actualy store the value in
    if(argc < 2 || scanf(argv[1], "%d", &n) == 0 || n < 0 || n > MAX){
        error(argv[0]);
    }
    printf("fib2(%d) = %lu\n", n, fib2(n));

    delete [] vals;
}