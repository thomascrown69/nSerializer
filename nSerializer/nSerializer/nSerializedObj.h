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

#endif /* defined(__nSerializer__nSerializedObj__) */




class nSerializedObj
{

private:
    long counter;
    long max;
    char* buffer;

    void resizeBufferNeeded(long& _size);
    
public:
    nSerializedObj();
    ~nSerializedObj();

    char* getBytes();
    int getSize();
    
    void writeInt32(int& input);
};
