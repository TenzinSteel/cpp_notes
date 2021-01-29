/**
 * introduction to classes
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef const char *String;

class Person{
    private:
        int age;
        string name;

    public:
        // constructor verson 1
        // Person(string n, int a){
        //     name = n;
        //     age = a;
        // }

        // costructor version 2 (better)
        // sets our private variables to whatever the user put in the constructor
        // this constructor lets you pass in arguments
        Person(string n, int a) : name(n), age(a) {
        }

         // default constructor
         // sets these variables if you create an instance of the person class
         // without arguments
        Person() : name("john"), age(99){
        }

        // method
        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        void setName(string new_name){
            name = new_name;
        }

        void setAge(int new_age){
        }

        void dump(string tag){
            cout << "[" << tag << "] " << name << " " << age << endl;
        }
};

// example of an explicit keyword
class Color{
    private:
        double _red, _green, _blue;

        // this is a "helper function"
        double _check(double v){
            if(v < 0 || v > 255){
                return 0;
            }
            return v;
        }
    
    public:
        // default constructor
        Color() : _red(0), _green(0), _blue(0){
        }

        // single param constructor
        // by using "explicit", the user must instantiate using this method:
        // Color c1(value)
        // instead of 
        // Color c1 = Value
        // which would work if we didnt have explicit
        explicit Color(double value) : 
        _red(_check(value)), _green(_check(value)), _blue(_check(value)){
        }

        // normal constructor
        Color(double r, double g, double b) :  _red(_check(r)), _green(_check(g)), _blue(_check(b)){
        }

        // note capital String.. only works this way for some reason
        void dump(String tag){
             printf("%s (%.f,%.f,%.f)\n",tag, _red, _green, _blue);
        }

        double vaue(){
            return _red + _blue + _green;
        }
};

int main(){
    
    Person p1("Tenzin", 20);
    cout << p1.getName() << endl;
    p1.setName("charles");
    cout << p1.getName() << endl;
    p1.dump("p1");
    Person p2;
    p2.dump("p2");

    Color c1(1);
    Color c2;
    Color c3(25,100,79);

    c1.dump("c1");
    c2.dump("c2");
    c3.dump("c3");

    // dynamic
    // using the "new" keyword, you are assigning the color values to the pointer
    Color *c4p = new Color(93, 251, 47);
    printf("c4p->value() = %lf\n", c4p->vaue());

    // note the different syntax for printf when its not a pointer
    Color c5(121,199,14);
    printf("c5.value() = %lf\n", c5.vaue());

    delete c4p;

}

// sample output

// Tenzin
// charles
// [p1] charles 20
// [p2] john 99
// c1 (1,1,1)
// c2 (0,0,0)
// c3 (25,100,79)
// c4p->value() = 391.000000
// c5.value() = 334.000000