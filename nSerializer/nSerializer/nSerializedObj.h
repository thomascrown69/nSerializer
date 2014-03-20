//
//  nSerializedObj.h
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#ifndef __nSerializer__nSerializedObj__
#define __nSerializer__nSerializedObj__

#include <iostream>

#define byteSize_writeInt32 5
#define byteSize_writeInt64 9

#endif


class nSerializedObj
{

private:
    long counter;
    long max;
    long current;
    char* buffer;
    
    void resizeBufferNeeded(long _size);
    
public:
    nSerializedObj();
    ~nSerializedObj();

    char* getBytes();
    long getSize();
    
    void writeInt32(int input);
    void writeInt64(int input);
    void writeChars(char* input);
    void writeDouble(double input);
    void writeFloat(float input);
    
    
};
