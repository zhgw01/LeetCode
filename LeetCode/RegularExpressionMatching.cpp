//
//  RegularExpressionMatching.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 5/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "RegularExpressionMatching.h"

using namespace std;

void RegularExpressionMatching::test1()
{
    char s[] = "aa";
    char p[] = "a*";
    
    bool result = isMatch(s, p);
    assert(result == true);
}

void RegularExpressionMatching::test2()
{
    char s[] = "a";
    char p[] = "ab*a";
    
    bool result = isMatch(s, p);
    assert(result == false);
}

void RegularExpressionMatching::test3()
{
    char s[] = "aasdfasdfasdfasdfas";
    char p[] = "aasdf.*asdf.*asdf.*asdf.*s";
    
    bool result = isMatch(s, p);
    assert(result == true);
}

void RegularExpressionMatching::run()
{
    cout << "Run Regular Expression Matching" << endl;
    test3();
  
}

size_t RegularExpressionMatching::minLength(const char *p)
{
    size_t result = 0;
    
    //should not begin with '*'
    if (*p == '*')
        return result;
        
    
    while (*p != 0) {
        if (*p == '*') {
            assert(result > 0);
            if (result == 0) {
                //illegal pattern
                return result;
            }
            --result;
        }
        else
            ++result;
        
        ++p;
    }
    
    return result;
}

bool RegularExpressionMatching::isMatch(const char *s, const char *p)
{
    assert(s && p);
    
    if (*p == 0) {
        return *s == 0;
    }
    
    //not pattern x*
    if (*(p +1) != '*') {
        assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != 0)) && isMatch(s+1, p+1);
    }
    
    //pattern x*
    while ((*p == *s) || (*p == '.' && *s != 0)) {
        if (isMatch(s, p + 2)) {
            return true;
        }
        ++s;
    }
    
    //skip pattern x*
    return isMatch(s, p + 2);
}