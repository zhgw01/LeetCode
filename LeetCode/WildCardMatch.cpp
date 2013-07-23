//
//  WildCardMatch.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "WildCardMatch.h"

using namespace std;

void WildCardMatch::run()
{
    cout<<"Run WildCardMatch"<<endl;
    test1();
}

void WildCardMatch::test1()
{
    const char* s= "ba";
    const char* p = "*a*";
    
    bool result = isMatch(s, p);
    bool expected = true;
    
    assert(result == expected);
}

void WildCardMatch::test3()
{
    const char* s= "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    const char* p = "a*******b";
    
    bool result = isMatch(s, p);
    bool expected = false;
    
    assert(result == expected);

}


void WildCardMatch::test2()
{
    const char* s= "aa";
    const char* p = "a";
    
    bool result = isMatch(s, p);
    bool expected = false;
    
    assert(result == expected);

}

bool WildCardMatch::isMatch(const char *s, const char *p)
{
    const char *str, *pat;
    bool star = false;
    
    for (str = s, pat = p; *str != '\0'; ++str, ++pat)
    {
        switch(*pat)
        {
                // 遇到'?',那么不管*str是任何字母都能匹配
            case '?':
                break;
            case '*':
                star = true;
                // 暂时忽略‘*’
                s = str;
                p = pat;
                do
                {
                    ++p;
                }while(*p == '*');
                // 如果'*'之后，pat是空的，直接返回true
                if (!*p)
                    return true;
                // 重新开始匹配
                str = str - 1;
                pat = p - 1;
                break;
            default:
                if (*str != *pat)
                {
                    // 如果前面没有'*'，则匹配不成功
                    if (!star)
                        return false;
                    // 从s的下一位和'*'之后的p重新开始匹配
                    ++s;
                    str = s - 1;
                    pat = p - 1;
                }
                break;
        }
    }
    
    while (*pat == '*')
        ++pat;
    return (!*pat);  }