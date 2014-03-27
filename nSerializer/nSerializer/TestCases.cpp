//
//  TestCases.cpp
//  nSerializer
//
//  Created by GEO on 23/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "TestCases.h"

int16_t t01 = INT16_MAX;
uint16_t t02 = UINT16_MAX;
int16_t t03 = INT16_MIN;
uint16_t t04 = 4;

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

//long t16 = 4346731323546432;
//long t17 = -123246575343234;

////////////////////////////

char* t18;
char* t19;
char* t20;

////////////////////////////

std::string t21;
std::string t22;
std::string t23;

////////////////////////////

float t24 = 0.1;
float t25 = -0.5;
float t26 = 435.34;

#if defined( _WIN32 ) || defined( _WIN64 )
float t27 = FLT_MAX;
#else
float t27 = MAXFLOAT;
#endif

double t28 = -95743.2;
double t29 = 93.1;
double t30 = 43599.43533;
double t31 = -0.3413;

////////////////////////////

//arrays
uint64_t t32Size = 4;
uint32_t* t32;

uint64_t t33Size = 4;
int64_t* t33;

uint64_t t34Size = 4;
float* t34;

uint64_t t35Size = 6;
double* t35;

////////////////////////////

Benchmarker* bench;

TestCases::TestCases()
{
    typedef std::numeric_limits< double > dbl;
    std::cout.precision(dbl::digits10);
    
    ////////////////////////////
    
    bench = new Benchmarker();
    
    t18 = (char*) malloc(6);
    strncpy(t18, "ZdsadA" , 6);
    t18[6] = '\0';
    
    int t19Size = 3024;
    t19 = (char*) malloc(t19Size+1);
    uint32_t i=0;
    while(i != t19Size)
    {
        t19[i] = 'Z';
        i++;
    }
    t19[t19Size] = '\0';
    
    int t20Size =19024;
    t20 = (char*) malloc(t20Size+1);
    i=0;
    while(i != t20Size)
    {
        t20[i] = 'T';
        i++;
    }
    t20[t20Size] = '\0';
    
    t21 = "S";
    t22 = "Zds@adsadas@@@dsadsaM";
    i = 0;
    while( i != 3024 )
    {
        t23.push_back('A');
        i++;
    }
    
    t32 = (uint32_t*) malloc(t32Size*4);
    t32[0] = 35;
    t32[1] = 4356;
    t32[2] = 4353;
    t32[3] = 43;
    
    t33 = (int64_t*) malloc(t33Size*8);
    t33[0] = -35;
    t33[1] = 4356;
    t33[2] = -1531323;
    t33[3] = 934119;

    t34 = (float*) malloc(t34Size*4);
    t34[0] = -4353.12323f;
    t34[1] = 0.4353f;
    t34[2] = 343151.9f;
    t34[3] = -0.32319f;
    
    t35 = (double*) malloc(t35Size*8);
    t35[0] = -4353.12434323;
    t35[1] = 0.443353;
    t35[2] = 343151.9413413;
    t35[3] = -0.3231913143;
    t35[4] = 0.3143;
    t35[5] = -0.3;
}


void TestCases::testWriteAllArraysValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL ARRAY VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    obj->writeUInt32Array(t32, t32Size);
    obj->writeInt64Array(t33, t33Size);
    obj->writeFloatArray(t34, t34Size);
    obj->writeDoubleArray(t35, t35Size);
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write(obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}

void TestCases::testReadAllArraysValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL ARRAY VALUES";
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    uint32_t* _t32;
    obj->readUInt32Array(&_t32);
    int64_t* _t33;
    obj->readInt64Array(&_t33);

    float* _t34;
    obj->readFloatArray(&_t34);
    double* _t35;
    obj->readDoubleArray(&_t35);
    
    bench->stop();
    std::cout << "\n\n\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
    
    std::cout << "\n";
    
    int i = 0;
    
    int faultsT32 = 0;
    while( i != t32Size )
    {
        if( _t32[i] != t32[i] )
        {
            std::cout << " \nError: t32[" << i << "] != _t32[" << i << "] ( " << t32[i] << " != " << _t32[i] << " ) ";
            faultsT32++;
        }
        i++;
    }
    if(faultsT32 == 0)
    {
        std::cout << "\nSuccess t32 == _t32";
    }
    
    i = 0 ;
    int faultsT33 = 0;
    while( i != t33Size )
    {
        if( _t33[i] != t33[i] )
        {
            std::cout << " \nError: t33[" << i << "] != _t33[" << i << "] ( " << t33[i] << " != " << _t33[i] << " ) ";
            faultsT33++;
        }
        i++;
    }
    if(faultsT33 == 0)
    {
        std::cout << "\nSuccess t33 == _t33";
    }

    
    i = 0 ;
    int faultsT34 = 0;
    while( i != t34Size )
    {
        if( _t34[i] != t34[i] )
        {
            std::cout << " \nError: t34[" << i << "] != _t34[" << i << "] ( " << t34[i] << " != " << _t34[i] << " ) ";
            faultsT34++;
        }
        i++;
    }
    if(faultsT34 == 0)
    {
        std::cout << "\nSuccess t34 == _t34";
    }
    
    i = 0 ;
    int faultsT35 = 0;
    while( i != t35Size )
    {
        if( _t35[i] != t35[i] )
        {
            std::cout << " \nError: t35[" << i << "] != _t35[" << i << "] ( " << t35[i] << " != " << _t35[i] << " ) \n";
            faultsT35++;
        }
        i++;
    }
    if(faultsT35 == 0)
    {
        std::cout << "\nSuccess t35 == _t35";
    }
    
    
    free(_t32);
    free(_t33);
    free(_t34);
    free(_t35);
    
}


void TestCases::testWriteAllFloatingPointsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL FLOATING POINT VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    obj->writeFloat(t24);
    obj->writeFloat(t25);
    obj->writeFloat(t26);
    obj->writeFloat(t27);
    
    obj->writeDouble(t28);
    obj->writeDouble(t29);
    obj->writeDouble(t30);
    obj->writeDouble(t31);
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write(obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}

void TestCases::testReadAllFloatingPointsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL FLOATING POINT VALUES";
    
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    float _t24 = obj->readFloat();
    float _t25 = obj->readFloat();
    float _t26 = obj->readFloat();
    float _t27 = obj->readFloat();
    
    double _t28 = obj->readDouble();
    double _t29 = obj->readDouble();
    double _t30 = obj->readDouble();
    double _t31 = obj->readDouble();
    
    if(_t24 != t24)
    { std::cout << " \nFloat Error: t24 != _t24 ( " << t24 << " != " << _t24 << " ) "; } else { std::cout << " \nFloat Success: t24 == _t24 ( " << t24 << " == " << _t24 << " ) "; }

    if(_t25 != t25)
    { std::cout << " \nFloat Error: t25 != _t25 ( " << t25 << " != " << _t25 << " ) "; } else { std::cout << " \nFloat Success: t25 == _t25 ( " << t25 << " == " << _t25 << " ) "; }

    if(_t26 != t26)
    { std::cout << " \nFloat Error: t26 != _t26 ( " << t26 << " != " << _t26 << " ) "; } else { std::cout << " \nFloat Success: t26 == _t26 ( " << t26 << " == " << _t26 << " ) "; }

    if(_t27 != t27)
    { std::cout << " \nFloat Error: t27 != _t27 ( " << t27 << " != " << _t27 << " ) "; } else { std::cout << " \nFloat Success: t27 == _t27 ( " << t27 << " == " << _t27 << " ) "; }

    
    if(_t28 != t28)
    { std::cout << " \nDouble Error: t28 != _t28 ( " << t28 << " != " << _t28 << " ) "; } else { std::cout << " \nDouble Success: t28 == _t28 ( " << t28 << " == " << _t28 << " ) "; }
    
    if(_t29 != t29)
    { std::cout << " \nDouble Error: t29 != _t29 ( " << t29 << " != " << _t29 << " ) "; } else { std::cout << " \nDouble Success: t29 == _t29 ( " << t29 << " == " << _t29 << " ) "; }
    
    if(_t30 != t30)
    { std::cout << " \nDouble Error: t30 != _t30 ( " << t30 << " != " << _t30 << " ) "; } else { std::cout << " \nDouble Success: t30 == _t30 ( " << t30 << " == " << _t30 << " ) "; }
    
    if(_t31 != t31)
    { std::cout << " \nDouble Error: t31 != _t31 ( " << t31 << " != " << _t31 << " ) "; } else { std::cout << " \nDouble Success: t31 == _t31 ( " << t31 << " == " << _t31 << " ) "; }
    
    bench->stop();
    std::cout << "\n\n\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
}

void TestCases::testWriteAllCharsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL CHARS VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    obj->writeChars(t18);
    obj->writeChars(t19);
    obj->writeChars(t20);
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write(obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}


void TestCases::testReadAllCharsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL CHARS VALUES";
    
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    char* _t18, *_t19, *_t20;
    obj->readChars(&_t18);
    obj->readChars(&_t19);
    obj->readChars(&_t20);
    
    bench->stop();
    std::cout << "\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
    
    if(strcmp(_t18, t18) != 0)
    { std::cout << " \nError: t18 != _t18 ( " << strlen(t18) << " != " << strlen(_t18) << " ) "; } else { std::cout << " \nSuccess: t18 == _t18 ( " << strlen(t18) << " != " << strlen(_t18) << " ) "; }

    //std::cout << "\n\n _t18 : " << _t18;
	//std::cout << " \n\n\n ";
	//std::cout << " t18 : " << t18;
	//std::cout << " \n\n\n ";
    
    if(strcmp(_t19, t19) != 0)
    { std::cout << " \nError: t19 != _t19 ( " << strlen(t19) << " != " << strlen(_t19) << " ) "; } else { std::cout << " \nSuccess: t19 == _t19 ( " << strlen(t19) << " != " << strlen(_t19) << " ) "; }
    
	//std::cout << "\n\n _t19 : " << _t19;
	//std::cout << " \n\n\n ";
	//std::cout << " t19 : " << t19;
	//std::cout << " \n\n\n ";
     
    if(strcmp(_t20, t20) != 0)
    { std::cout << " \nError: t20 != _t20 ( " << strlen(t20) << " != " << strlen(_t20) << " ) "; } else { std::cout << " \nSuccess: t20 == _t20 ( " << strlen(t20) << " != " << strlen(_t20) << " ) "; }
    
    //std::cout << "\n\n _t20 : " << _t20;
	//std::cout << " \n\n\n ";
	//std::cout << " t20 : " << t20;
	//std::cout << " \n\n\n ";
    
    free(_t18);
    free(_t19);
    free(_t20);

}

void TestCases::testWriteAllStringsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL STRING VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    obj->writeString(t21);
    obj->writeString(t22);
    obj->writeString(t23);
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write(obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}

void TestCases::testReadAllStringsValues()
{
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING READ ALL STRING VALUES";
    
    std::ifstream input_file("data.tx", std::ios::binary);
    input_file.seekg (0, input_file.end);
    long length = input_file.tellg();
    input_file.seekg (0, input_file.beg);
    char* pInputFile = (char*) malloc( length );
    input_file.read(pInputFile, length);
    
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    std::string _t21, _t22, _t23;
    _t21 = obj->readString();
    _t22 = obj->readString();
    _t23 = obj->readString();
    
    bench->stop();
    std::cout << "\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();

    if(t21.compare(_t21) != 0)
    { std::cout << " \nError: t21 != _t21 ( " << t21.length() << " != " << _t21.length() << " ) "; } else { std::cout << " \nSuccess: t21 == _t21 ( " << t21.length() << " != " << _t21.length() << " ) "; }
    
    //std::cout << "\n\n _t21 : " << _t21;
	//std::cout << " \n\n ";
	//std::cout << " t21 : " << t21;
	//std::cout << " \n\n\n ";
    
    if(t22.compare(_t22) != 0)
    { std::cout << " \nError: t22 != _t22 ( " << t22.length() << " != " << _t22.length() << " ) "; } else { std::cout << " \nSuccess: t22 == _t22 ( " << t22.length() << " != " << _t22.length() << " ) "; }
    
    //std::cout << "\n\n _t22 : " << _t22;
	//std::cout << " \n\n ";
	//std::cout << " t22 : " << t22;
	//std::cout << " \n\n\n ";
    
    if(t23.compare(_t23) != 0)
    { std::cout << " \nError: t23 != _t23 ( " << t23.length() << " != " << _t23.length() << " ) "; } else { std::cout << " \nSuccess: t23 == _t23 ( " << t23.length() << " != " << _t23.length() << " ) "; }
    
    //std::cout << "\n\n _t23 : " << _t23;
	//std::cout << " \n\n ";
	//std::cout << " t23 : " << t23;
	//std::cout << " \n\n\n ";
    
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
    
    int16_t _t01;
    uint16_t _t02;
    int16_t _t03;
    uint16_t _t04;
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
    //long _t16;
    //long _t17;
    
    BaseSerializedObj* obj = new BaseSerializedObj(length, pInputFile);
    bench->start();
    
    _t01 = obj->readInt16();
    _t02 = obj->readUInt16();
    _t03 = obj->readInt16();
    _t04 = obj->readUInt16();
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
    //_t16 = obj->readInt64();
    //_t17 = obj->readInt64();
    
    bench->stop();
    std::cout << "\n READ time taken : ";
    bench->getAll();
    free(pInputFile);
    input_file.close();
    obj->~BaseSerializedObj();
    
    if(_t01 != t01)
    { std::cout << " \nError: t01 != _t01 ( " << t01 << " != " << _t01 << " ) "; } else { std::cout << " \nSuccess: t01 == _t01 ( " << t01 << " == " << _t01 << " ) "; }
    
    if(_t02 != t02)
    { std::cout << " \nError: t02 != _t02 ( " << t02 << " != " << _t02 << " ) "; } else { std::cout << " \nSuccess: t02 == _t02 ( " << t02 << " == " << _t02 << " ) "; }
    
    if(_t03 != t03)
    { std::cout << " \nError: t03 != _t03 ( " << t03 << " != " << _t03 << " ) "; } else { std::cout << " \nSuccess: t03 == _t03 ( " << t03 << " == " << _t03 << " ) "; }
    
    if(_t04 != t04)
    { std::cout << " \nError: t04 != _t04 ( " << t04 << " != " << _t04 << " ) "; } else { std::cout << " \nSuccess: t04 == _t04 ( " << t04 << " == " << _t04 << " ) "; }
    
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
    
    //if(_t16 != t16)
    //{ std::cout << " \nError: t16 != _t16 ( " << t16 << " != " << _t16 << " ) "; } else { std::cout << " \nSuccess: t16 == _t16 ( " << t16 << " == " << _t16 << " ) "; }
    
    //if(_t17 != t17)
    //{ std::cout << " \nError: t17 != _t17 ( " << t17 << " != " << _t17 << " ) "; } else { std::cout << " \nSuccess: t17 == _t17 ( " << t17 << " == " << _t17 << " ) "; }
    
    std::cout << "\n\n";
}

void TestCases::testWriteAllIntValues()
{
    
    std::cout << "\n-----------------------------\n";
    std::cout << "TESTING WRITE ALL INT VALUES";
    BaseSerializedObj* obj = new BaseSerializedObj(32);
    bench->start();
    
    obj->writeInt16(t01);
    obj->writeUInt16(t02);
    
    obj->writeInt16(t03);
    obj->writeUInt16(t04);
    
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
    
    //obj->writeInt64(t16);
    //obj->writeInt64(t17);
    
    
    bench->stop();
    std::cout << "\n WRITE time taken : ";
    bench->getAll();
    std::ofstream output_file("data.tx", std::ios::binary);
    output_file.write( obj->getBytes(), obj->getSize());
    output_file.close();
    obj->~BaseSerializedObj();
    std::cout << "\n\n";
}
