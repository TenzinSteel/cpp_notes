/**
 * dynamic allocation practice
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <random>
#include <sstream>

#define RAND() (100000 + rand() % 90000)
#define SIZE 10

using namespace std;
typedef unsigned long Ulong;

class Student{
    private:
        string _name;
        double _gpa;
    public:
        Student() : _name("----"), _gpa(0.00){
        }
        Student(string n, double g) : _name(n), _gpa(g){
        }
        ~Student(){
        }
        // functions
        void dump(){
                printf("%s GPA: %.2lf\n", _name.c_str(), _gpa);
            }
        const string toString() const{
            stringstream ss;

            ss << "name: " << this->_name << " gpa: " << this->_gpa << "\n";

            return ss.str();
        }
};

int main(){

    // this array has no name
    // the pointer excists in the stack
    // access values from array by using pointer
    int *dynamicArr = new int[SIZE];

    for(int i = 0; i < SIZE; i++){
        
        dynamicArr[i] = rand() % 10 +1;
        printf("%d, ",dynamicArr[i]);
    }
    delete [] dynamicArr;

    cout << endl;

    // example of an array of a class
    // creates an array of students
    Student *studentArr = new Student[SIZE];
    
    // you can access it like a normal array with the pointer
    studentArr[5] = Student("Tenzin", 3.80);
    studentArr[7] = Student("bobo", 4.00);

    for(int i = 0; i < SIZE; i++){
        // i can access methods in the student class with this pointer?
        studentArr[i].dump();
    }
    delete [] studentArr;
}