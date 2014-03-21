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
#include "Helpers.h"
#include <math.h>

#define byteSize_writeInt32 5
#define byteSize_writeInt64 9
#define byteSize_writeChars 5
#define byteSize_writeString 5
#define byteSize_writeFloat 9

#define Int32_Type 0x01
#define Int64_Type 0x02

#define Double_Type 0x05
#define Float_Type 0x07

#define Chars_Type 0x09
#define String_Type 0x0A


#endif


class nSerializedObj
{

    private:
        long counter;
        long max;
        long current;
        char* buffer;

        void writeByte(int b);
        char readByte();
        char readByteAt(int _counter);
    
        void resizeBufferNeeded(long _size);
    
    public:
        nSerializedObj(long defaultBufferSize);
        nSerializedObj(long defaultBufferSize, char* bytearray);
        ~nSerializedObj();

        static nSerializedObj createSerializedObjFrom(char* bytearray);
    
        char* getBytes();
        long getSize();

        void writeInt32(uint32_t input);
        void writeLong(unsigned long input);
        void writeChars(char* input);
        void writeDouble(double input);
        void writeFloat(float input);
        void writeString(std::string input);
    
        int readInt32();
        unsigned long readLong();
        char* readChars();
        double readDouble();
        float readFloat();
        std::string readString();
};
