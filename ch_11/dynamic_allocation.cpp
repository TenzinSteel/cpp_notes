/**
 * dynamic allocation, distructors, copy constructor
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <random>

#define RAND() (100000 + rand() % 90000)
#define CLASS_SIZE 30

using namespace std;
typedef unsigned long Ulong;


class Student{
    private:
        string _name;
        double _gpa;
        Ulong _id;

    public:
        // constructors
        Student(string n, Ulong id, double gpa) : _name(n), _id(id), _gpa(gpa){
        }
        Student() : _name("NAME"), _id(RAND()), _gpa(0.00){
        }
        // accessors
        string getName(){
            return _name;
        }
        double getGPA(){
            return _gpa;
        }
        Ulong getId(){
            return _id;
        }
        //mutators
        bool setGPA(double gpa){
            if (gpa < 0 || gpa > 4){
                return false;
            }
            _gpa = gpa;
            return true; 
        }
        void setName(string name){
            _name = name;
        }
        bool setId(Ulong id){
            if (id > 999999 || id < 000000){
                return false;
            }
            _id = id;
            return true;
        }
        // other
        void dump(){
            printf("%s ID: %d GPA: %.2lf\n", _name.c_str(), _id, _gpa);
        }
};

class Class{
    private:
        // making with pointer because we are planing to use it as a dynamic array
        // the class holds "max" number of students.
        Student *_students;
        int _size, _cap;

    public:
        // costructor
        Class(int max){
            // creating an array of the student class with a size "max"
            // Student instances are dynamicaly allocated, using default constructor
            _students = new Student[max];
            _size = 0;
            _cap = max;
        }

        // default constructor
        Class(){
            _students = new Student[CLASS_SIZE];
            _size = 0;
            _cap = CLASS_SIZE;
        }

        // copy constructor
        Class(const Class &c){
            _size = 0;
            _students= new Student[c._cap];
            printf("copy constructor\n");
        }

        // destructor
        // called every time the instance is de-allocated
        // ALWAYS implament distructors to clear memory (resources) durring the
        // lifetime of the class
        ~Class(){
            printf("~Class()\n");
            delete [] _students;
        }

        // mutator
        bool addStudent(Student s){
            if(_size == _cap){
                return false;
            }
            // note how we incrament _size
            _students[_size++] = s;
            return true;
        }
        
        // accessor
        bool getStudent(int num, Student *s){
            if(num < 0 || num >= _size){
                return false;
            }
            *s = _students[num];
            return true;
        }
        // void getClass(string tag){
        //     for(int i = 0; i < _size; i++){
        //         cout << _students[i];
        //     }
        // }

        int getSize(){
            return _size;
        }
};

// NOT GONNA USE IN MAIN PROGRAM
// use of sprintf, VERY powerful
// prints into the string variable "num" so we can return the variable
string phone(){
    char num[13];
    // needs to be 13 because null char at the end
    sprintf(num, "%3d-%3d-%4d", rand(), rand(), rand());
    return num;
}

int main(){
    // cs3a is an "automatic" variable, created on the stack
    // but, its internal atributes _students holds memory on the heap
    // which is not de-allocated automatically

    // crerates 30 instances of the "Student" class with the default constructor
    Class cs3a(CLASS_SIZE);

    // loop to add students into the class
    for(int i = 0; i < CLASS_SIZE; i++){
        if(!cs3a.addStudent(Student())){
            printf("[%d]: could not add student\n", i);
        }
    }

    Student s;
    for(int i = 0; i < CLASS_SIZE; i++){
        if (cs3a.getStudent(i, &s)){
            s.dump();
        }
    }

    Class cs3aCopy = cs3a;
    printf("cs3acopy.size() = %d\n", cs3aCopy.getSize());
}