/**
 * inheritance notes
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <random>

using namespace std;

// implamenting typedef
typedef unsigned long Ulong;
typedef const char *String;

// create a randomn 6-dig number
// this is called a "macro"
#define RAND() (100000 + rand() % 90000)

// PCC member (student, faculty, staff)
class Member{
    // make "protected" so the derived classes can access the variables
    protected:
        Ulong _id;
        String _name;

    public:
        // input constructor
        Member( String name, Ulong id) : _name(name), _id(id) {
        }

        // default constructor
        Member() :  _name("----"), _id(RAND()){
        }

        // methods
        void dump(String tag){
            printf("[%s] %s, ID:%d\n", tag, _name, _id);
        }

        Ulong getId(){
            return _id;
        }

        String getName(){
            return _name;
        }
};

class Student : public Member{
private:
    double _gpa;
    
public:
    // now we can access the variables from the Member class
    Student(String n, Ulong id, double gpa) : Member() {
        _name = n;
        _id = id;
        _gpa = gpa;
    }

    Student() {
    }

    double getGPA(){
        return _gpa;
    }

    bool setGPA(double gpa){
        if (gpa < 0 || gpa > 4){
            return false;
        }
        _gpa = gpa;
        return true; 
    }
    // note the function calls from the master class
    void dump(String tag){
        printf("[%s] %s ID: %d GPA: %.2lf\n", tag, getName(), getId(), _gpa);
    }
};

int main(){
    Student s1;
    printf("s1: ID = %d, GPA = %.2lf\n", s1.getId(), s1.getGPA());

    s1.setGPA(3.8);
    s1.dump("s1");

    // using inheritance
    Student s2("Tenzin", 123456, 3.80);
    s2.dump("s2");

    return 0;
}
