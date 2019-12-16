//
// Created by kevin on 11/20/2019.
//

#include "myMath.h"
#include <numeric>

int myMath::plus(int a, int b) {
    return a + b;
}

int myMath::minus(int a, int b) {
    return a - b;
}

int myMath::multiply(int a, int b) {
    return a * b;
}

int myMath::divide(int a, int b) {
    return a / b;
}

int myMath::plusRef(int &a, int &b) {
    return a + b;
}

int myMath::plusVec(std::vector<int> a, std::vector<int> b) {
    return accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
}

int myMath::plusVecRef(std::vector<int> &a, std::vector<int> &b) {
    return accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
}
