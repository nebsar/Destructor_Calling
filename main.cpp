/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 14, 2018, 2:19 AM
 */

#include <iostream>

class Base {
    int a;
public:

    Base() {
        std::cout << "Base Constructor is called\n";
    }

    virtual ~Base() {
        std::cout << "Base Destructor is called\n";
    }
};

class Derived : public Base {
public:

    Derived() {
        std::cout << "Derived Constructor is called\n";
    }

    virtual ~Derived() {
        std::cout << "Derived Destructor is called\n";
    }
};

int main() {
    //// Normal csse
    std::cout << "Normal Case\n";
    Base* obj = new Base();
    delete obj;

    ///////placement new case:
    std::cout << "placement new Case\n";

    std::cout << "Size of Base is : " << sizeof (Base) << '\n';
    char* memory = new char[10 * sizeof (Base)];

    /*since the size of Base is 16 (because  we declare a virtual destructor)
     * we are using increments of 16.
     */

    Base* obj1 = new (&memory[0]) Base(); //memory location is explicitly indicated here
    Base* obj2 = new (&memory[16]) Base(); //memory location is explicitly indicated here
    Base* obj3 = new (&memory[32]) Base(); //memory location is explicitly indicated here

    obj1->~Base();
    obj2->~Base();
    obj3->~Base();

    delete[] memory;

    return 1;
}

