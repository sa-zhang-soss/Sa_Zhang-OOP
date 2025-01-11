#pragma once
#include <iostream>
#include <string>

template <typename T>
T mymin(T& a, T& b) {
    return (a < b) ? a : b;
}