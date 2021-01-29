/**
 * check for palindromes using recursion
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <cstdio>
#include <cstring>
#define SIZE 0x100 

/**
 * isPali checks if given string is a palindrome.
 * - s: string to check
 * - n: length of the string
 */
bool isPali(const char *s, int n){
    // base case, dont forget
    if(n < 2){
        return true;
    }
    if(s[0] != s[n - 1]){
        return false;
    }
    return isPali(s + 1, n - 2);
}

int main(){
    char s[SIZE];
    // loop ends when there is no more input
    while(scanf("%s", s) > 0){
        // good way to check t/f stuff
        printf("%s\n", isPali(s, strlen(s)) ? "palindrome" : "Not palindrome");
    }
}