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

void BaseSerializedObj::writeChar(char b)
{
    buffer[counter] = b;
    counter++;
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

uint16_t BaseSerializedObj::readUInt16()
{
    uint16_t r =
    (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8;
    return r;
}

int16_t BaseSerializedObj::readInt16()
{
    int16_t r =
    (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8;
    return r;
}

uint32_t BaseSerializedObj::readUInt32()
{
    uint32_t r =
    (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8 |
    (readByte() & 0xFF) << 16 |
    (readByte() & 0xFF) << 24;
    return r;
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

void BaseSerializedObj::readChars(char** p)
{
    int length = readInt32();
    *p = (char*) malloc(length+1);
    int i = 0;
    while(i != length)
    {
        (*p)[i] = readByte();
        i++;
    }
    (*p)[length] = '\0';
}


float BaseSerializedObj::readFloat()
{
    unsigned char* a = (unsigned char* ) readInt32();
    return *(float *) &a;
}


double BaseSerializedObj::readDouble()
{
    int floor = readInt32();
    float frac = readFloat();
    double n = floor + frac;
    return n;
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

void BaseSerializedObj::readUInt16Array(uint16_t** o)
{
    uint64_t size = readUInt64();
    *o = (uint16_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readUInt16();
        i++;
    }
}

void BaseSerializedObj::readInt16Array(int16_t** o)
{
    uint64_t size = readUInt64();
    *o = (int16_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readInt16();
        i++;
    }
}

void BaseSerializedObj::readUInt32Array(uint32_t** o)
{
    uint64_t size = readUInt64();
    *o = (uint32_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readUInt32();
        i++;
    }
}

void BaseSerializedObj::readInt32Array(int32_t** o)
{
    uint64_t size = readUInt64();
    *o = (int32_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readInt32();
        i++;
    }
}

void BaseSerializedObj::readUInt64Array(uint64_t** o)
{
    uint64_t size = readUInt64();
    *o = (uint64_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readUInt64();
        i++;
    }
}

void BaseSerializedObj::readInt64Array(int64_t** o)
{
    uint64_t size = readUInt64();
    *o = (int64_t *) malloc(size);
    uint64_t i = 0;
    while(i != size)
    {
        (*o)[i] = readInt64();
        i++;
    }
}

void BaseSerializedObj::writeUInt16(uint16_t input)
{
    resizeBufferNeeded( byteSize_writeUInt16 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
}

void BaseSerializedObj::writeInt16(int16_t input)
{
    resizeBufferNeeded( byteSize_writeInt16 );
    unsigned char * p = (unsigned char *) &input;
    writeByte(p[0]);
    writeByte(p[1]);
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

//my custom double packing
//double precision floating-point, doesn't use the IEEE 754 format
void BaseSerializedObj::writeDouble(double input)
{
    int floor = Helpers::floor_to_zero(input);
    double frac = input - floor;
    writeInt32(floor);
    writeFloat(frac);
}

//only supports char arrays of length value of 4 bytes
void BaseSerializedObj::writeChars(char* input)
{
    int size = strlen(input);
    resizeBufferNeeded(size+1);
    writeInt32(size);
    int y = 0;
    while( y < size )
    {
        writeByte(input[y]);
        y++;
    }
    buffer[counter] = '\0';
}

void BaseSerializedObj::writeString(std::string input)
{
    int size = input.length();
    resizeBufferNeeded(size);
    writeInt32(size);
    int y = 0;
    while( y < size )
    {
        writeByte(input[y]);
        y++;
    }
}

void BaseSerializedObj::writeInt16Array(int16_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeInt16(array[i]);
        i++;
    }
}

void BaseSerializedObj::writeUInt16Array(uint16_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeUInt16(array[i]);
        i++;
    }
}

void BaseSerializedObj::writeInt32Array(int32_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeInt32(array[i]);
        i++;
    }
}

void BaseSerializedObj::writeUInt32Array(uint32_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeUInt32(array[i]);
        i++;
    }
}

void BaseSerializedObj::writeInt64Array(int64_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeInt64(array[i]);
        i++;
    }
}

void BaseSerializedObj::writeUInt64Array(uint64_t array[], uint64_t s)
{
    writeUInt64(s);
    uint64_t i = 0;
    while ( i!=s )
    {
        writeUInt64(array[i]);
        i++;
    }
}