//
//  TestCases.cpp
//  nSerializer
//
//  Created by GEO on 23/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "TestCases.h"

int32_t t0 = INT32_MIN;
uint32_t t1 = 0;

int32_t t2 = -34353;
int32_t t3 = 983843;

uint32_t t4 = 9438538;

int32_t t5 = INT32_MAX;
uint32_t t6 = UINT32_MAX;

int t7 = 4314;
int t8 = -9564;

int64_t t9 = INT64_MIN;
uint64_t t10 = 0;

int64_t t11 = -343534343534358;
int64_t t12 = 9838438145343;

uint64_t t13 = 943853843435343;

int64_t t14 = INT64_MAX;
uint64_t t15 = UINT64_MAX;

long t16 = 4346731323546432;
long t17 = -123246575343234;


Benchmarker* bench;

TestCases::TestCases()
{
    bench = new Benchmarker();
}

void TestCases::testReadAllIntValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL INT MAX VALUES";
    
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    
    int32_t _t0;
    uint32_t _t1;
    int32_t _t2;
    int32_t _t3;
    uint32_t _t4;
    int32_t _t5;
    uint32_t _t6;
    int _t7;
    int _t8;
    int64_t _t9;
    uint64_t _t10;
    int64_t _t11;
    int64_t _t12;
    uint64_t _t13;
    int64_t _t14;
    uint64_t _t15;
    long _t16;
    long _t17;
    
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    _t0 = obj->readInt32();
    _t1 = obj->readUInt32();
    _t2 = obj->readInt32();
    _t3 = obj->readInt32();
    _t4 = obj->readUInt32();
    _t5 = obj->readInt32();
    _t6 = obj->readUInt32();
    _t7 = obj->readInt32();
    _t8 = obj->readInt32();
    
    _t9 = obj->readInt64();
    _t10 = obj->readUInt64();
    _t11 = obj->readInt64();
    _t12 = obj->readInt64();
    _t13 = obj->readUInt64();
    _t14 = obj->readInt64();
    _t15 = obj->readUInt64();
    _t16 = obj->readInt64();
    _t17 = obj->readInt64();
    
    bench->stop();
    std::cout << "\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
    
    if(_t0 != t0) { std::cout << " \nError: t0 failed "; }
    if(_t1 != t1) { std::cout << " \nError: t1 failed "; }
    if(_t2 != t2) { std::cout << " \nError: t2 failed "; }
    if(_t3 != t3) { std::cout << " \nError: t3 failed "; }
    if(_t4 != t4) { std::cout << " \nError: t4 failed "; }
    if(_t5 != t5) { std::cout << " \nError: t5 failed "; }
    if(_t6 != t6) { std::cout << " \nError: t6 failed "; }
    if(_t7 != t7) { std::cout << " \nError: t7 failed "; }
    if(_t8 != t8) { std::cout << " \nError: t8 failed "; }
    if(_t9 != t9) { std::cout << " \nError: t9 failed "; }
    if(_t10 != t10) { std::cout << " \nError: t10 failed "; }
    if(_t11 != t11) { std::cout << " \nError: t11 failed "; }
    if(_t12 != t12) { std::cout << " \nError: t12 failed "; }
    if(_t13 != t13) { std::cout << " \nError: t13 failed "; }
    if(_t14 != t14) { std::cout << " \nError: t14 failed "; }
    if(_t15 != t15) { std::cout << " \nError: t15 failed "; }
    if(_t16 != t16) { std::cout << " \nError: t16 failed "; }
    if(_t17 != t17) { std::cout << " \nError: t17 failed "; }
    std::cout << "\n\n";
}

void TestCases::testWriteAllIntValues()
{
    
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL INT MAX VALUES";
    bench->start();
    
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    
    obj->writeInt32(t0);
    obj->writeUInt32(t1);
    
    obj->writeInt32(t2);
    obj->writeInt32(t3);
    
    obj->writeUInt32(t4);
    
    obj->writeInt32(t5);
    obj->writeUInt32(t6);
    
    obj->writeInt32(t7);
    obj->writeInt32(t8);
    
    obj->writeInt64(t9);
    obj->writeUInt64(t10);
    
    obj->writeInt64(t11);
    obj->writeInt64(t12);
    
    obj->writeUInt64(t13);
    
    obj->writeInt64(t14);
    obj->writeUInt64(t15);
    
    obj->writeInt64(t16);
    obj->writeInt64(t17);
    
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}
