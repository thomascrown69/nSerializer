//
//  nSerializedObj.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "nSerializedObj.h"
#include "Helpers.h"

//constructor
nSerializedObj::nSerializedObj()
{
    buffer = (char*)malloc(10); //JUST an initial size.. todo for better memory management
    counter = 0;
    max = 10; //just an initial size
    current = 0;
}

nSerializedObj::~nSerializedObj()
{
    free(buffer);
}

/*
void nSerializedObj::resizeBufferNeeded(long& _size)
{
    char* tmp = (char*)malloc(sizeof(buffer));
    strcpy(tmp, buffer);
    free(buffer);
    buffer = (char*) malloc(16);
    max += _size;
    free(tmp);
}*/

void nSerializedObj::resizeBufferNeeded(long _size)
{
    long dif = labs(max - counter);
    if( dif < _size )
    {
        buffer = (char*)realloc(buffer, labs(dif-_size));
        max += _size;
    }
    current = current + _size;
}

void nSerializedObj::writeByte(int b)
{
    buffer[counter] = b;
    counter++;
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


//longs can by any byte size, my implementation stacks
//32 bit ints.
void nSerializedObj::writeLong(unsigned long input)
{
    std::cout << " ttotalbytes: " << Helpers::bytesOfLong(input);
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
    while( i < 7 )
    {
        writeByte(n[i]);
        i++;
    }
}


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
