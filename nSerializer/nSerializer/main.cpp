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

    std::cout << "Hello, nSerializer World!\n";
    
    nSerializedObj* obj = new nSerializedObj(32);
    
    char* test0 = "georgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgeLLL";
    
    int test1 = 3232;
    int test2 = 2147483647;
    int test3 = -214748364;
    unsigned long test4 = 67455702834; // <- wont work
    
    char* test5 = "dasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasdATSA";
    
    std::string test6 = "stringtestetststring";
    
    float test7 = 21333.93339;
    
    unsigned long test8 =5147483647;
    
    obj->writeChars(test0);
    obj->writeInt32(test1);
    obj->writeInt32(test2);
    obj->writeInt32(test3);
    obj->writeLong(test4);
    obj->writeChars(test5);
    obj->writeString(test6);
    obj->writeFloat(test7);
    obj->writeLong(test8);
    
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    
    
    obj->~nSerializedObj();
    
    
    return 0;
}

