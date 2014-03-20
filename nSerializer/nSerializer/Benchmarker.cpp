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
    startValue = 0;
    stopValue = 0;
    delta = 0;
}


void Benchmarker::start()
{
    gettimeofday(&t, &tzp);
    startValue = t.tv_sec + t.tv_usec*1e-6;
}

void Benchmarker::stop()
{
    gettimeofday(&t, &tzp);
    stopValue =  t.tv_sec + t.tv_usec*1e-6;
    delta = stopValue - startValue;
}

double Benchmarker::get()
{
    return delta;
}