//
//  nSerializedObj.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "nSerializedObj.h"


nSerializedObj::nSerializedObj(long bufferSize, char* bytearray)
{
    buffer = (char*)malloc(bufferSize);
    counter = 0;
    max = bufferSize;
    current = bufferSize;
    
    memcpy(buffer, bytearray, bufferSize);
}

nSerializedObj::nSerializedObj(long defaultBufferSize)
{
    buffer = (char*)malloc(defaultBufferSize);
    counter = 0;
    max = defaultBufferSize;
    current = 0;
}

nSerializedObj::~nSerializedObj()
{
    free(buffer);
}

void nSerializedObj::resizeBufferNeeded(long _size)
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
        free(tmp);
        
    }
    current = current + _size;
}

void nSerializedObj::writeByte(int b)
{
    buffer[counter] = b;
    counter++;
}

char nSerializedObj::readByte()
{
    char r = buffer[counter];
    counter++;
    std::cout << " \n b: " << counter << " |= " << r;
    return r;
}

char nSerializedObj::readByteAt(int _counter)
{
    char r = buffer[_counter];
    counter = _counter + 1;
    return r;
}

char* nSerializedObj::getBytes()
{
    return buffer;
}

long nSerializedObj::getSize()
{
    return max;
}

void nSerializedObj::writeInt32(uint32_t input)
{
    resizeBufferNeeded( (long)byteSize_writeInt32 );
    writeByte(Int32_Type);
    char n[4];
    n[0] = (input & 0xFF);
    n[1] = (input & 0xFF00) >> 8;
    n[2] = (input & 0xFF0000) >> 16;
    n[3] = (input & 0xFF000000) >> 24;
    int i = 0;
    while( i < 4 )
    {
        writeByte(n[i]);
        i++;
    }
}


int nSerializedObj::readInt32()
{
    counter++;
    unsigned int x = (readByte() & 0xFF) |
    (readByte() & 0xFF) << 8 |
    (readByte() & 0xFF) << 16 |
    (readByte() & 0xFF) << 24;
    return x;
}

unsigned long nSerializedObj::readLong()
{
    counter++;
    char n[8];
    n[0] = readByte();
    n[1] = readByte();
    n[2] = readByte();
    n[3] = readByte();
    n[4] = readByte();
    n[5] = readByte();
    n[6] = readByte();
    n[7] = readByte();
    
    unsigned long x = ( ((n[7] & 0xff) << 56) | ((n[6] & 0xff) << 48) | ((n[5] & 0xff) << 40) | ((n[4] & 0xff) << 32) | ((n[3] & 0xff) << 24) | ((n[2] & 0xff) << 16) | ((n[1] & 0xff) << 8) | ((n[0] & 0xff)) );
    
    return x;

}

char* nSerializedObj::readChars()
{
    int length = readInt32();
    char* r = (char*) malloc(length);
    std::cout << " \n length: " << length;
    return r;
}

//longs can by any byte size, my implementation stacks
//32 bit ints.
void nSerializedObj::writeLong(unsigned long input)
{
    resizeBufferNeeded( (long)byteSize_writeInt64 );
    writeByte(Int64_Type);
    char n[8];
    n[0] = (input & 0xFF);
    n[1] = (input & 0xFF00) >> 8;
    n[2] = (input & 0xFF0000) >> 16;
    n[3] = (input & 0xFF000000) >> 24;
    n[4] = (input & 0xFF0000000) >> 32;
    n[5] = (input & 0xFF00000000) >> 40;
    n[6] = (input & 0xFF000000000) >> 48;
    n[7] = (input & 0xFF0000000000) >> 56;
    int i = 0;
    while( i < 8 )
    {
        writeByte(n[i]);
        i++;
    }
}


//
void nSerializedObj::writeDouble(double input)
{
    int decim = (int) input;
    int frac =  Helpers::frac_notrailingzeros(input, 8);
    resizeBufferNeeded(byteSize_writeFloat);
    writeByte(Double_Type);
    char n1[4];
    n1[0] = (decim & 0xFF);
    n1[1] = (decim & 0xFF00) >> 8;
    n1[2] = (decim & 0xFF0000) >> 16;
    n1[3] = (decim & 0xFF000000) >> 24;
    int i = 0;
    while( i < 4 )
    {
        writeByte(n1[i]);
        i++;
    }
    
    char n2[4];
    n2[0] = (frac & 0xFF);
    n2[1] = (frac & 0xFF00) >> 8;
    n2[2] = (frac & 0xFF0000) >> 16;
    n2[3] = (frac & 0xFF000000) >> 24;
    i = 0;
    while( i < 4 )
    {
        writeByte(n2[i]);
        i++;
    }
    
}



//this float implementation can only be 4 bytes . 4 bytes long
void nSerializedObj::writeFloat(float input)
{
    int decim = (int) input;
    int frac =  Helpers::frac_notrailingzeros(input, 4);
    resizeBufferNeeded(byteSize_writeFloat);
    writeByte(Float_Type);
    char n1[4];
    n1[0] = (decim & 0xFF);
    n1[1] = (decim & 0xFF00) >> 8;
    n1[2] = (decim & 0xFF0000) >> 16;
    n1[3] = (decim & 0xFF000000) >> 24;
    int i = 0;
    while( i < 4 )
    {
        writeByte(n1[i]);
        i++;
    }

    char n2[4];
    n2[0] = (frac & 0xFF);
    n2[1] = (frac & 0xFF00) >> 8;
    n2[2] = (frac & 0xFF0000) >> 16;
    n2[3] = (frac & 0xFF000000) >> 24;
    i = 0;
    while( i < 4 )
    {
        writeByte(n2[i]);
        i++;
    }
    
}

//only supports char arrays of length value of 4 bytes
void nSerializedObj::writeChars(char* input)
{
    int size = strlen(input);
    resizeBufferNeeded(byteSize_writeChars + size);
    writeByte(Chars_Type);
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
    if(!input)
    {
        free(input);
    }
}

//only supports char arrays of length value of 4 bytes
void nSerializedObj::writeString(std::string input)
{
    int size = input.length();
    resizeBufferNeeded(byteSize_writeString + size);
    writeByte(String_Type);
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