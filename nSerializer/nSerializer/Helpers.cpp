//
//  Helpers.cpp
//  nSerializer
//
//  Created by GEO on 20/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "Helpers.h"
#include <iostream>
#include <cmath>

long Helpers::bytesOfLong(long input)
{
    long n = 0;
    while (input != 0) {
        input >>= 8;
        n ++;
    }
    return n;
}

//Knuth section 4.2.2
bool Helpers::isEqual(double x, double y)
{
    const double epsilon = 1e-5;
    return std::abs(x - y) <= epsilon * std::abs(x);
}

double Helpers::round(double value) {
    return (value > 0.0) ? std::floor(value + 0.5) : std::ceil(value - 0.5);
}

double Helpers::floor_to_zero(double value) {
    return (value > 0.0) ? std::floor(value) : std::ceil(value);
}

double Helpers::sign(double value) {
    return (value < 0.0) ? -1.0 : 1.0;
}

int Helpers::frac(double value, int precision) {
    return (int)((value - (long)value) * pow(10, precision));
}

int Helpers::frac_notrailingzeros(double value, int precision)
{
    int v = frac(value, precision);
    while (v % 10 == 0)
    {
        v /= 10;
    }
    return v;
}




