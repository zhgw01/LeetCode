//
//  LastWorldLength.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LastWorldLength.h"

using namespace std;

void LastWorldLength::run()
{
    cout<<"Run LastWorldLength"<<endl;
    test1();
}

void LastWorldLength::test1()
{
    const char* s = "Hello World";
    
    int result = lengthOfLastWord(s);
    int expected = 5;
    
    assert(result == expected);
}

int LastWorldLength::lengthOfLastWord(const char *s)
{
    if (!s) {
        return 0;
    }
    
    int length = strlen(s);
    int start = 0;
    int end = 0;
    bool next = true;
    
    for (int i = 0; i < length; ++i) {
        if (s[i] == ' ') {
            if (!next) {
                end = i;
            }
            next = true;
        }
        else if(next) {
            start = i;
            next = false;
        }
    }
    
    if (!next) {
        end = length;
    }
    
    return end - start;
}