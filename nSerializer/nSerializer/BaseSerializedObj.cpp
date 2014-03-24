//
//  nSerializedObj.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "BaseSerializedObj.h"


BaseSerializedObj::BaseSerializedObj(long bufferSize, char* bytearray)
{
    buffer = (char*)malloc(bufferSize);
    counter = 0;
    max = bufferSize;
    current = bufferSize;
    
    memcpy(buffer, bytearray, bufferSize);
}

BaseSerializedObj::BaseSerializedObj(long defaultBufferSize)
{
    buffer = (char*)malloc(defaultBufferSize);
    counter = 0;
    max = defaultBufferSize;
    current = 0;
}

BaseSerializedObj::~BaseSerializedObj()
{
    free(buffer);
}

void BaseSerializedObj::resizeBufferNeeded(long _size)
{
    long dif2 = labs(current + _size);
    long dif1 = labs(max - dif2);
    if( dif2 > max )
    {
        char* tmp = (char*) malloc ( current );
        memcpy(tmp, buffer, max);
        free(buffer);
        max = max + dif1;
        buffer = (char*) malloc(max);
        memcpy(buffer, tmp, max);
		if(!tmp)
		{
			free(tmp);
		}
    }
    current = current + _size;
}

void BaseSerializedObj::writeByte(int b)
{
    buffer[counter] = b;
    counter++;
}

char BaseSerializedObj::readByte()
{
    char r = buffer[counter];
    counter++;
    return r;
}


char BaseSerializedObj::readByteAt(int _counter)
{
    char r = buffer[_counter];
    counter = _counter + 1;
    return r;
}


char* BaseSerializedObj::getBytes()
{
    return buffer;
}


long BaseSerializedObj::getSize()
{
    return max;
}


uint32_t BaseSerializedObj::readUInt32()
{
    uint32_t x =
    (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8 |
    (readByte() & 0xFF) << 16 |
    (readByte() & 0xFF) << 24;
    return x;
}

int32_t BaseSerializedObj::readInt32()
{
    int32_t r =
    (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8 |
    (readByte() & 0xFF) << 16 |
    (readByte() & 0xFF) << 24;
    return r;
}

int64_t BaseSerializedObj::readInt64()
{
    int64_t r =
    ((int64_t)readByte() & 0xFF) |
    ((int64_t)readByte() & 0xFF) << 8 |
    ((int64_t)readByte() & 0xFF) << 16 |
    ((int64_t)readByte() & 0xFF) << 24 |
    ((int64_t)readByte() & 0xFF) << 32 |
    ((int64_t)readByte() & 0xFF) << 40 |
    ((int64_t)readByte() & 0xFF) << 48 |
    ((int64_t)readByte() & 0xFF) << 56;
    return r;
}

uint64_t BaseSerializedObj::readUInt64()
{
    uint64_t r =
    ((uint64_t)readByte() & 0xFF) |
    ((uint64_t)readByte() & 0xFF) << 8 |
    ((uint64_t)readByte() & 0xFF) << 16 |
    ((uint64_t)readByte() & 0xFF) << 24 |
    ((uint64_t)readByte() & 0xFF) << 32 |
    ((uint64_t)readByte() & 0xFF) << 40 |
    ((uint64_t)readByte() & 0xFF) << 48 |
    ((uint64_t)readByte() & 0xFF) << 56;
    
    return r;
    
}

char* BaseSerializedObj::readChars()
{
    int length = readUInt32();
	std::cout << " length " << length;
    char* r = (char*) malloc(length);
    int i = 0;
    while(i != length)
    {
        r[i] = readByte();
        i++;
    }
    return r;
}


float BaseSerializedObj::readFloat()
{
    unsigned char* a = (unsigned char* ) readInt32();
    return *(float *) &a;
}


double BaseSerializedObj::readDouble()
{
    unsigned char* a = (unsigned char* ) readUInt64();
    return *(float *) &a;
}


std::string BaseSerializedObj::readString()
{
    int length = readInt32();
    std::string r = "";
    int i = 0;
    while(i != length)
    {
        r.push_back(readByte());
        i++;
    }
    return r;
}


void BaseSerializedObj::writeUInt32(uint32_t input)
{
    resizeBufferNeeded( byteSize_writeUInt32 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
}

void BaseSerializedObj::writeInt32(int32_t input)
{
    resizeBufferNeeded( byteSize_writeInt32 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
}



void BaseSerializedObj::writeInt64(int64_t input)
{
    resizeBufferNeeded( byteSize_writeUInt64 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
    writeByte(p[4]);
    writeByte(p[5]);
    writeByte(p[6]);
    writeByte(p[7]);
}



void BaseSerializedObj::writeUInt64(uint64_t input)
{
    resizeBufferNeeded( byteSize_writeUInt64 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
    writeByte(p[4]);
    writeByte(p[5]);
    writeByte(p[6]);
    writeByte(p[7]);
}

//single precision floating-point | IEEE 754
void BaseSerializedObj::writeFloat(float input)
{
    resizeBufferNeeded(byteSize_writeFloat);
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
}


//double precision floating-point | IEEE 754
void BaseSerializedObj::writeDouble(double input)
{
    resizeBufferNeeded(byteSize_writeDouble);
    
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
    writeByte(p[2]);
    writeByte(p[3]);
    writeByte(p[4]);
    writeByte(p[5]);
    writeByte(p[6]);
    writeByte(p[7]);
    
    
}


//only supports char arrays of length value of 4 bytes
void BaseSerializedObj::writeChars(char* input)
{
    int size = strlen(input);
    resizeBufferNeeded(byteSize_writeChars + size);
    writeUInt32(size);
    int y = 0;
    while( y < size )
    {
        writeByte(input[y]);
        y++;
    }
    //free(input);
    
}


//only supports char arrays of length value of 4 bytes
void BaseSerializedObj::writeString(std::string input)
{
    int size = input.length();
    resizeBufferNeeded(byteSize_writeString + size);
    char n[4];
    n[0] = (size & 0xFF);
    n[1] = (size & 0xFF00) >> 8;
    n[2] = (size & 0xFF0000) >> 16;
    n[3] = (size & 0xFF000000) >> 24;
    //apply the length binary sequence
    int i = 0;
    while( i < 4 )
    {
        writeByte(n[i]);
        i++;
    }
    //apply the string binary sequence
    int y = 0;
    while( y < size )
    {
        writeByte(input[y]);
        y++;
    }
}