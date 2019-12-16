// OOP2WK3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "calculator.h"


int main() {

    int a = 0, b = 0;
    char operatorChar = ' ';
    std::cout << "input a number: " << std::endl;
    std::cin >> a;
    std::cout << "input a math operator: " << std::endl;
    std::cin >> operatorChar;
    std::cout << "input the next number: " << std::endl;
    std::cin >> b;
    calculator::input(a, operatorChar, b);
}
