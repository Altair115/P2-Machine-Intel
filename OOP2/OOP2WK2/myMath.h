//
// Created by kevin on 11/20/2019.
//

#ifndef INC_2NDPERIOD_MYMATH_H
#define INC_2NDPERIOD_MYMATH_H

#include <vector>


class myMath {
public:
    static int plus(int a, int b);

    static int minus(int a, int b);

    static int multiply(int a, int b);

    static int divide(int a, int b);

    static int plusRef(int &a, int &b);

    static int plusVec(std::vector<int> a, std::vector<int> b);

    static int plusVecRef(std::vector<int> &a, std::vector<int> &b);
};


#endif //INC_2NDPERIOD_MYMATH_H
