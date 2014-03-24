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
#include <chrono>

#endif 


class Benchmarker
{
    private:
        std::chrono::high_resolution_clock::time_point startValue;
        std::chrono::high_resolution_clock::time_point stopValue;
    
    public:
        Benchmarker();
        ~Benchmarker();
    
        void start();
        void stop();
        void getMS();
        void getNS();
        void getAll();
};