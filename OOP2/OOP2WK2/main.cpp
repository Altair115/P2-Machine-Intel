// OOP2WK1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include "myMath.h"


int main() {

    int a = 0, b = 0;
    char operatorChar = ' ';
    std::cout << "input a number: " << std::endl;
    std::cin >> a;
    std::cout << "input a math operator: " << std::endl;
    std::cin >> operatorChar;
    std::cout << "input the next number: " << std::endl;
    std::cin >> b;

    switch (operatorChar) {
        case '+':
            printf("%d + %d = %d", a, b, myMath::plus(a, b));
            break;
        case '-':
            printf("%d - %d = %d", a, b, myMath::minus(a, b));
            break;
        case '*':
            printf("%d * %d = %d", a, b, myMath::multiply(a, b));
            break;
        case '/':
            printf("%d / %d = %d", a, b, myMath::divide(a, b));
            break;
        default:
            std::cout << "Not available: " << operatorChar << std::endl;
    }
    
}
