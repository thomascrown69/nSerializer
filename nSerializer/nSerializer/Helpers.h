#ifdef WIN32
#pragma pack( 1 )
#endif
//
//  Helpers.h
//  nSerializer
//
//  Created by GEO on 20/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#ifndef __nSerializer__Helpers__
#define __nSerializer__Helpers__

#include <iostream>

#endif 


class Helpers
{
    
    public:
        static bool isEqual(double x, double y);
        static long bytesOfLong(long input);
        static double round(double r);
        static double floor_to_zero(double f);
        static double sign(double s);
        static int frac(double f, int prec);
        static int frac_notrailingzeros(double value, int precision);
    
};

