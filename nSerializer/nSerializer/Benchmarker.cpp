//
//  Benchmarker.cpp
//  nSerializer
//
//  Created by GEO on 20/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "Benchmarker.h"


Benchmarker::Benchmarker()
{
    
}


void Benchmarker::start()
{
    startValue = std::chrono::high_resolution_clock::now();
}

void Benchmarker::stop()
{
    stopValue = std::chrono::high_resolution_clock::now();
}

void Benchmarker::getMS()
{
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stopValue - startValue).count() << " ms\n";
}

void Benchmarker::getNS()
{
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(stopValue - startValue).count() << " ns\n";
}

void Benchmarker::getAll()
{
    auto diff = stopValue - startValue;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stopValue - startValue).count() << " ms " << std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() << " ns\n" << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << " mics\n";
}