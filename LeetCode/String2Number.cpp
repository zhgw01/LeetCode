//
//  String2Number.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 4/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "String2Number.h"

using namespace std;

void String2Number::run()
{
    cout << "Running String To Number" <<endl;
    test5();
 }


int String2Number::atoi(const char *str)
{
    if (!str)
        return 0;
    
    //skip the leading empty
    size_t strLength = strlen(str);
    const char* numberString = NULL;
    for (int i = 0; i < strLength; ++i) {
        if (' ' != str[i] && '\t' != str[i]) {
            numberString = &str[i];
            break;
        }
    }
    
    if (!numberString) {
        return 0;
    }
    
    size_t length = strlen(numberString);
    int result = 0;
    bool bMinus = false;
    
    if (length > 0) {
        if ('-' == numberString[0]) {
            bMinus = true;
        } else if ('0' <= numberString[0] && numberString[0] <= '9')
        {
            result = numberString[0] - '0';
        }
        else if('+' != numberString[0])
            return result;
    }
    
    for (int i = 1; i < length; ++i) {
        
        if('0' <= numberString[i] && numberString[i] <= '9')
        {
            int oldResult = result;
            result = result * 10 + (numberString[i] - '0');
            //overflow
            if (result / 10 != oldResult) {
                if (bMinus) {
                    return INT_MIN;
                }
                else
                    return INT_MAX;
            }
        }
        else
            break;
        
    }
    
    if (bMinus) {
        return -result;
    }
    else
        return result;
}

void String2Number::test1()
{
    char str[] = "-1234509";
    int result = atoi(str);
    int expected = -1234509;
    assert(result == expected);

}

void String2Number::test2()
{
    char str[] = "";
    int result = atoi(str);
    int expected = 0;
    assert(result == expected);

}

void String2Number::test3()
{
    char str[] = "+00131204";
    int result = atoi(str);
    int expected = 131204;
    assert(result == expected);

}

void String2Number::test4()
{
    char str[] = "-10519048889";
    int result = atoi(str);
    int expected = -2147483648;
    assert(result == expected);
}

void String2Number::test5()
{
    char str[] = "        r11384376420";
    int result = atoi(str);
    int expected = 0;
    assert(result == expected);
}
