//
// Created by kevin on 11/28/2019.
//

#include "calculator.h"
#include <iostream>

void calculator::input(const int a, const char opChar, const int b) {
    switch (opChar) {
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
            std::cout << "Not available: " << opChar << std::endl;
    }
}
