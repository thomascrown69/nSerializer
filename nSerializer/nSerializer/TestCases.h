#ifdef WIN32
#pragma pack( 1 )
#endif
//
//  TestCases.h
//  nSerializer
//
//  Created by GEO on 23/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#ifndef __nSerializer__TestCases__
#define __nSerializer__TestCases__

#include "Benchmarker.h"
#include <iostream>
#include <fstream>
#include "BaseSerializedObj.h"

#endif 

class TestCases
{
    private:
    
    public:
    TestCases();
    
    void testReadAllIntValues();
    void testWriteAllIntValues();
    
    void testWriteAllCharsValues();
    void testReadAllCharsValues();
};
