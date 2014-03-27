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
    std::cout << "*** Press 3 to test Write Chars --- testWriteAllCharsValues() \n";
    std::cout << "*** Press 4 to test Read Chars --- testReadAllCharsValues() \n";
    std::cout << "*** Press 5 to test Write Strings --- testWriteAllStringsValues() \n";
    std::cout << "*** Press 6 to test Read Strings --- testReadAllStringsValues() \n";
    std::cout << "*** Press 7 to test Write Floating Points --- testWriteAllFloatingPointsValues() \n";
    std::cout << "*** Press 8 to test Read Floating Points --- testReadAllFloatingPointsValues() \n";
    std::cout << "*** Press 9 to test Write Arrays --- testWriteAllArraysValues() \n";
    std::cout << "*** Press 10 to test Read Arrays --- testReadAllArraysValues() \n";
    
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
            ts->testWriteAllCharsValues();
        }
        else if ( i==4 )
        {
            ts->testReadAllCharsValues();
        }
        else if ( i==5 )
        {
            ts->testWriteAllStringsValues();
        }
        else if ( i==6 )
        {
            ts->testReadAllStringsValues();
        }
        else if ( i==7 )
        {
            ts->testWriteAllFloatingPointsValues();
        }
        else if ( i==8 )
        {
            ts->testReadAllFloatingPointsValues();
        }
        else if ( i==9 )
        {
            ts->testWriteAllArraysValues();
        }
        else if ( i==10 )
        {
            ts->testReadAllArraysValues();
        }
        
        std::cin >> i;
    }
    

    return 0;
}



