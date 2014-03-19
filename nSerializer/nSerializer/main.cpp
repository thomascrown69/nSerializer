//
//  main.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "nSerializedObj.h"

int main(int argc, const char * argv[])
{

    nSerializedObj* obj = new nSerializedObj();
    
    int test1 = 3232;
    int test2 = 2147483647;
    int test3 = -214748364;
    
    
    obj->writeInt32(test1);
    obj->writeInt32(test2);
    obj->writeInt32(test3);
    
    
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    
    // insert code here...
    std::cout << "Hello, nSerializer World!\n";
    return 0;
}

