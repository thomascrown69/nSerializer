//
//  Helpers.cpp
//  nSerializer
//
//  Created by GEO on 20/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "Helpers.h"


long Helpers::bytesOfLong(long input)
{
    long n = 0;
    while (input != 0) {
        input >>= 8;
        n ++;
    }
    return n;
}