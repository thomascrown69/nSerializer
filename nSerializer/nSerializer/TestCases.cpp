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

////////////////////////////

char* t18;
char* t19;
char* t20;

////////////////////////////

Benchmarker* bench;

TestCases::TestCases()
{
    bench = new Benchmarker();
    
}


void TestCases::testWriteAllCharsValues()
{
    
    //t18 = "NasrZ";
    
    t19 = (char*) malloc(1024);
    uint32_t i=0;
    while(i != 1024)
    {
        t19[i] = 'A';
        i++;
    }
    
    t20 = (char*) malloc(967295);
    //populuate 4294967295
    i=0;
    while(i != 967295)
    {
        t20[i] = 'B';
        i++;
    }
    
    
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL CHARS MAX VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    //obj->writeChars(t18);
    obj->writeChars(t19);
    //obj->writeChars(t20);
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}


void TestCases::testReadAllCharsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL CHARS MAX VALUES";
    
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    //char* _t18 = obj->readChars();
    char* _t19 = obj->readChars();
    //char* _t20 = obj->readChars();
    
    bench->stop();
    std::cout << "\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
    
    //if(strcmp(_t18, t18) != 0)
    //{ std::cout << " \nError: t18 != _t18 ( " << strlen(t18) << " != " << strlen(_t18) << " ) "; } else { std::cout << " \nSuccess: t18 == _t18 ( " << strlen(t18) << " != " << strlen(_t18) << " ) "; }
    
    if(strcmp(_t19, t19) != 0)
    { std::cout << " \nError: t19 != _t19 ( " << strlen(t19) << " != " << strlen(_t19) << " ) "; } else { std::cout << " \nSuccess: t19 == _t19 ( " << strlen(t19) << " != " << strlen(_t19) << " ) "; }
    
	std::cout << "\n\n _t19 : " << _t19;
	std::cout << " \n\n\n ";
	std::cout << " t19 : " << t19;

    //if(strcmp(_t20, t20) != 0)
    //{ std::cout << " \nError: t20 != _t20 ( " << strlen(t20) << " != " << strlen(_t20) << " ) "; } else { std::cout << " \nSuccess: t20 == _t20 ( " << strlen(t20) << " != " << strlen(_t20) << " ) "; }
    
    std::cout << "\n\n";
    
    //free(_t18);
    free(_t19);
    //free(_t20);

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
    
    if(_t0 != t0)
    { std::cout << " \nError: t0 != _t0 ( " << t0 << " != " << _t0 << " ) "; } else { std::cout << " \nSuccess: t0 == _t0 ( " << t0 << " == " << _t0 << " ) "; }
    
    if(_t1 != t1)
    { std::cout << " \nError: t1 != _t1 ( " << t1 << " != " << _t1 << " ) "; } else { std::cout << " \nSuccess: t1 == _t1 ( " << t1 << " == " << _t1 << " ) "; }
    
    if(_t2 != t2)
    { std::cout << " \nError: t2 != _t2 ( " << t2 << " != " << _t2 << " ) "; } else { std::cout << " \nSuccess: t2 == _t2 ( " << t2 << " == " << _t2 << " ) "; }
        
    if(_t3 != t3)
    { std::cout << " \nError: t3 != _t3 ( " << t3 << " != " << _t3 << " ) "; } else { std::cout << " \nSuccess: t3 == _t3 ( " << t3 << " == " << _t3 << " ) "; }
        
    if(_t4 != t4)
    { std::cout << " \nError: t4 != _t4 ( " << t4 << " != " << _t4 << " ) "; } else { std::cout << " \nSuccess: t4 == _t4 ( " << t4 << " == " << _t4 << " ) "; }
        
    if(_t5 != t5)
    { std::cout << " \nError: t5 != _t5 ( " << t5 << " != " << _t5 << " ) "; } else { std::cout << " \nSuccess: t5 == _t5 ( " << t5 << " == " << _t5 << " ) "; }
        
    if(_t6 != t6)
    { std::cout << " \nError: t6 != _t6 ( " << t6 << " != " << _t6 << " ) "; } else { std::cout << " \nSuccess: t6 == _t6 ( " << t6 << " == " << _t6 << " ) "; }
        
    if(_t7 != t7)
    { std::cout << " \nError: t7 != _t7 ( " << t7 << " != " << _t7 << " ) "; } else { std::cout << " \nSuccess: t7 == _t7 ( " << t7 << " == " << _t7 << " ) "; }
    
    if(_t8 != t8)
    { std::cout << " \nError: t8 != _t8 ( " << t8 << " != " << _t8 << " ) "; } else { std::cout << " \nSuccess: t8 == _t8 ( " << t8 << " == " << _t8 << " ) "; }
    
    if(_t9 != t9)
    { std::cout << " \nError: t9 != _t9 ( " << t9 << " != " << _t9 << " ) "; } else { std::cout << " \nSuccess: t9 == _t9 ( " << t9 << " == " << _t9 << " ) "; }
    
    if(_t10 != t10)
    { std::cout << " \nError: t10 != _t10 ( " << t10 << " != " << _t10 << " ) "; } else { std::cout << " \nSuccess: t10 == _t10 ( " << t10 << " == " << _t10 << " ) "; }
    
    if(_t11 != t11)
    { std::cout << " \nError: t11 != _t11 ( " << t11 << " != " << _t11 << " ) "; } else { std::cout << " \nSuccess: t11 == _t11 ( " << t11 << " == " << _t11 << " ) "; }
    
    if(_t12 != t12)
    { std::cout << " \nError: t12 != _t12 ( " << t12 << " != " << _t12 << " ) "; } else { std::cout << " \nSuccess: t12 == _t12 ( " << t12 << " == " << _t12 << " ) "; }
    
    if(_t13 != t13)
    { std::cout << " \nError: t13 != _t13 ( " << t13 << " != " << _t13 << " ) "; } else { std::cout << " \nSuccess: t13 == _t13 ( " << t13 << " == " << _t13 << " ) "; }
    
    if(_t14 != t14)
    { std::cout << " \nError: t14 != _t14 ( " << t14 << " != " << _t14 << " ) "; } else { std::cout << " \nSuccess: t14 == _t14 ( " << t14 << " == " << _t14 << " ) "; }
    
    if(_t15 != t15)
    { std::cout << " \nError: t15 != _t15 ( " << t15 << " != " << _t15 << " ) "; } else { std::cout << " \nSuccess: t15 == _t15 ( " << t15 << " == " << _t15 << " ) "; }
    
    if(_t16 != t16)
    { std::cout << " \nError: t16 != _t16 ( " << t16 << " != " << _t16 << " ) "; } else { std::cout << " \nSuccess: t16 == _t16 ( " << t16 << " == " << _t16 << " ) "; }
    
    if(_t17 != t17) 
    { std::cout << " \nError: t17 != _t17 ( " << t17 << " != " << _t17 << " ) "; } else { std::cout << " \nSuccess: t17 == _t17 ( " << t17 << " == " << _t17 << " ) "; }
    
    std::cout << "\n\n";
}

void TestCases::testWriteAllIntValues()
{
    
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL INT MAX VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
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
