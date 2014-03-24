//
//  main.cpp
//  nSerializer
//
//  Created by GEO on 19/03/2014.
//  Copyright (c) 2014 GEO. All rights reserved.
//

#include "TestCases.h"

TestCases* ts;

int main(int argc, const char * argv[])
{
    ts = new TestCases();
    std::cout << "Hello, nSerializer World!\n\n\n";
    std::cout << "*** Press 1 to test Write Ints --- testWriteAllIntValues() \n";
    std::cout << "*** Press 2 to test Read Ints --- testReadAllIntValues() \n";
    
    bool end = false;
    int i = 0;
    
    while(end == false)
    {
        if ( i==1 )
        {
            ts->testWriteAllIntValues();
        }
        else if ( i==2 )
        {
            ts->testReadAllIntValues();
        }
        else if ( i==3 )
        {
            
        }
        else if ( i==4 )
        {
            
        }
        
        std::cin >> i;
    }
    

    return 0;
}



