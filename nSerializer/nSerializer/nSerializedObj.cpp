//
//  nSerializedObj.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "nSerializedObj.h"

//constructor
nSerializedObj::nSerializedObj()
{
    buffer = (char*)malloc(8); //JUST an initial size.. todo for better memory management
    counter = 0;
    max = 8; //just an initial size
}

nSerializedObj::~nSerializedObj()
{
    free(buffer);
}

/*
void nSerializedObj::resizeBufferNeeded(long& _size)
{
    std::cout << " before: " << sizeof(buffer) << " | ";
    char* tmp = (char*)malloc(sizeof(buffer));
    strcpy(tmp, buffer);
    free(buffer);
    std::cout << " tmp: " << sizeof(tmp) << " | _size: " << _size;
    buffer = (char*) malloc(16);
    max += _size;
    free(tmp);
    
    std::cout << " after: " << sizeof(buffer) << " ";
}*/

void nSerializedObj::resizeBufferNeeded(long& _size)
{
    //if(_size > max)
    //{
        buffer = (char*)realloc(buffer, _size);
    
        //max += _size;
        std::cout << " \n realloc'd " << " _size " << _size;
    //}
    //else
    //{
        //max += _size;
    //}
    max += _size;
}

char* nSerializedObj::getBytes()
{
    return buffer;
}

int nSerializedObj::getSize()
{
    return max;
}

void nSerializedObj::writeInt32(int& input)
{
    long bytesSize = 5;
    resizeBufferNeeded(bytesSize);
    
    buffer[counter] = 0x01; // type byte
    counter++;
    
    char n[4];
    n[0] = (input & 0xFF);
    n[1] = (input & 0xFF00) >> 8;
    n[2] = (input & 0xFF0000) >> 16;
    n[3] = (input & 0xFF000000) >> 24;
    
    int i = 0;
    while( i < 4 )
    {
        buffer[counter] = n[i] ;
        i++;
        counter++;
    }
 
    std::cout << " \n strlen(buffer) " << strlen(buffer);
    
}


/*writeCharAsString(char* _input)
{
    int size = strlen(_input);
    
    char n[4];
    n[0] = (size & 0xFF);
    n[1] = (size & 0xFF00) >> 8;
    n[2] = (size & 0xFF0000) >> 16;
    n[3] = (size & 0xFF000000) >> 24;
    
    //apply the length binary sequence
    int i = 0;
    while( i < 4 )
    {
        buf[counter] = n[i] ;
        i++;
        counter++;
    }
    
    //apply the string binary sequence
    int y = 0;
    while( y < size )
    {
        buf[counter] = _input[y];
        y++;
        counter++;
    }
    
    
    if(!_input)
    {
        free(_input);
    }
}*/
