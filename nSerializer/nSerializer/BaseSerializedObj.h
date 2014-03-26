#ifdef WIN32
#pragma pack( 1 )
#endif
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
#include <math.h>
#include "Helpers.h"

#if defined( _WIN32 ) || defined( _WIN64 )

#include <stdint.h>
#include <Windows.h>

#else

#endif

#define byteSize_writeInt16 2
#define byteSize_writeUInt16 2
#define byteSize_writeUInt32 4
#define byteSize_writeInt32 4
#define byteSize_writeInt64 8
#define byteSize_writeUInt64 8
#define byteSize_writeChars 0
#define byteSize_writeString 0
#define byteSize_writeFloat 4
#define byteSize_writeDouble 8


#endif


class BaseSerializedObj
{

    private:
        long counter;
        long max;
        long current;
        char* buffer;

        void writeByte(int b);
        char readByte();
        char readByteAt(int _counter);
        void writeChar(char b);
    
        void resizeBufferNeeded(long _size);
    
    
        union d2b
        {
            double value;
            char bytes[sizeof (double)]; // avoid magic numbers
        };
    
    public:
        BaseSerializedObj(long defaultBufferSize);
        BaseSerializedObj(long defaultBufferSize, char* bytearray);
        ~BaseSerializedObj();

        static BaseSerializedObj createSerializedObjFrom(char* bytearray);
    
        char* getBytes();
        long getSize();

        void writeInt16(int16_t input);
        void writeInt32(int32_t input);
        void writeInt64(int64_t input);

        void writeUInt16(uint16_t input);
        void writeUInt32(uint32_t input);
        void writeUInt64(uint64_t input);
    
        void writeChars(char* input);
        void writeDouble(double input);
        void writeFloat(float input);
        void writeString(std::string input);
    
        uint16_t readUInt16();
        uint32_t readUInt32();
        uint64_t readUInt64();
    
        int16_t readInt16();
        int32_t readInt32();
        int64_t readInt64();
    
        void readChars(char** p);
        double readDouble();
        float readFloat();
        std::string readString();
};
