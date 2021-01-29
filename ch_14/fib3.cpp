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
// O(n) time complexity, O(1) space complexity
// fib by iteration
// basically updating a and b
uint64_t fib3(int n){
    uint64_t a = 0, b = 1;
    for(int i = 2; i <= n; i++){
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
} 

void error(const char *cmd){
    // this prints to stderr (error stream) and not stdout (standard stream)
    fprintf(stderr, "Usage: %s <+vs integer>\n", cmd);
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
    printf("fib3(%d) = %lu\n", n, fib3(n));
}