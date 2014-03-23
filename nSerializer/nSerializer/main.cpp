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
#include "Benchmarker.h"

int main(int argc, const char * argv[])
{

    std::cout << "Hello, nSerializer World!\n";
    
    
    Benchmarker* bench = new Benchmarker();
    
    char* test0 = "BgeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgegeorgeogeorgeLLL";
    
    int test1 = 3232;
    int test2 = 2147483647;
    int test3 = -214748364;
    unsigned long test4 = 2455702834; // more tests
    
    char* test5 = "AdasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasddasdsadsadasdasdasdasdATSA";
    
    std::string test6 = "EstringtestetststringZ";
    
    float test7 = -21333.93339;
    
    long test8 = 2155702834;
    
    double test9 = 93339.93339;
    
    bench->start();
    
    nSerializedObj* obj = new nSerializedObj(32);
    //obj->writeChars(test0);
    //obj->writeInt32(test1);
    //obj->writeInt32(test2);
    //obj->writeInt32(test3);
    //obj->writeLong(test4);
    //obj->writeChars(test5);
    //obj->writeString(test6);
    obj->writeFloat(test7);
    //obj->writeLong(test8);
    obj->writeDouble(test9);
    
    bench->stop();
    
    std::cout << "\n WRITE time taken : " << bench->getMS() << "ms \n ";
    
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    
    obj->~nSerializedObj();

    if(!test0)
    {
        free(test0);
    }
    if(!test5)
    {
        free(test5);
    }
    
    std::ifstream input_file("data.tx", std::ios::binary);
    
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);

    char* pInputFile = (char*) malloc( length );
    
    input_file.read(pInputFile, length);
    
    nSerializedObj* obj2 = new nSerializedObj(length, pInputFile);
    
    bench->start();

    //char* a= obj2->readChars();
    //int b = obj2->readInt32();
    //int c = obj2->readInt32();
    //int d = obj2->readInt32();
    //unsigned long e = obj2->readLong();
    //char* f = obj2->readChars();
    //std::string g = obj2->readString();
    //unsigned long h = obj2->readLong();
    float i = obj2->readFloat();
    float j = obj2->readDouble();
    
    //std::cout << " \n f: " << fl;
    
    printf( "\n i: %f", i );
    
    printf( "\n j: %f", j );
    
    
    bench->stop();
    
    //std::cout << "\n\n READ result: " << a << " | " << b << " | " << c << " | " << d << " | " << e << " | " << f << " | " << g << " | " << h << " \n ";
    
    
    std::cout << "\n READ time taken : " << bench->getMS() << "ms \n ";
    
    free(pInputFile);
    input_file.close();
    
    obj2->~nSerializedObj();
    
    //free(a);
    //free(f);
    
    return 0;
}

