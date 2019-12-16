//
// Created by kevin on 11/20/2019.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "myMath.h"


TEST_CASE("Benchmarks with int", "[myMath]") {
    int x = 50, y = 60;

    BENCHMARK("Compute speed with ref") {
                                            return myMath::plusRef(x, y);
                                        };
    BENCHMARK("Compute speed without ref") {
                                               return myMath::plus(x, y);
                                           };
}

TEST_CASE("Benchmarks with vector", "[myMath]") {
    std::vector<int> x = {1, 2, 3, 5, 8, 9}
    , y = {9, 54, 24, 64, 71, 14};

    BENCHMARK("Compute speed with ref") {
                                            return myMath::plusVecRef(x, y);
                                        };
    BENCHMARK("Compute speed without ref") {
                                               return myMath::plusVec(x, y);
                                           };
}