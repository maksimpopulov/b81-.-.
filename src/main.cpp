// Copyright 2022 UNN-IASR
#include "iosream"
#include "fun.h"

int main() {
    char* str = "sdf1 fsdf5sdfs gslll adfvs";
    std::cout << str << "\n";
    std::cout << "функция 1: " << faStr1(str) << "\n";
    std::cout << "функция 2: " << faStr2(str) << "\n";
    std::cout << "функция 3: " << faStr3(str) << "\n";
    return 0;
}
