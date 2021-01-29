
#include <iostream>
#include <string>

using namespace std;


int main(){
    
    string tag = "example";
    int value = 13;

    // use ".c_str()" inorder to print strings passed into values.
    printf("%s ___ %d\n",tag.c_str(), value);
   
}
