//
//  Benchmarker.h
//  nSerializer
//
//  Created by GEO on 20/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#ifndef __nSerializer__Benchmarker__
#define __nSerializer__Benchmarker__

#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

#endif 


class Benchmarker
{
    private:
        double startValue;
        double stopValue;
        double delta;
        struct timeval t;
        struct timezone tzp;
    public:
        Benchmarker();
        ~Benchmarker();
    
        void start();
        void stop();
        double get();
        double getMS();
};