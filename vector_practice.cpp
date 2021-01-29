/**
 * practice with vectors
 *
 * Copyright (C) 2021, Tenzin Steel
 */

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


struct Coordinates{
    float _x, _y, _z;

    Coordinates(float x, float y, float z) :
    _x(x), _y(y), _z(z){
    }
};

// so we can print coordinates
ostream& operator<<(ostream& stream, const Coordinates& coordinate){
    stream << coordinate._x << ", " << coordinate._y << ", " << coordinate._z;
    return stream;
}

// be sure to pass by reference so you dont coppy the entire array int the func
void printFunc(vector<int>& vector_name){
     for (int v : vector_name){
        cout << v << endl;
    }
    // can also print like this
    // for(int i = 0; i < vector_name.size(); i++){
    //     cout << myVector1[i] << endl;
    // }
}

// must pass by reference so it can actualy manipulate the vector and save changes
void fillFunc(vector<int>& vector_name){
    for(int i = 0; i < 10; i++){
        vector_name.push_back(i);
    }
}

// be sure to pass by reference so you dont coppy the entire array int the func
void printCoordinates(const vector<Coordinates>& vector_name){
    for (Coordinates v : vector_name){
        cout << v << endl;
    }
}

int main(){
    vector<int> myVector1;
    fillFunc(myVector1);
    printFunc(myVector1);

    vector<Coordinates> myVector2;
    myVector2.push_back({1,2,3});
    myVector2.push_back({4,5,6});
    myVector2.push_back({7,8,9});
    // if you want to erase the second element
    myVector2.erase(myVector2.begin() + 1);
    printCoordinates(myVector2);
}