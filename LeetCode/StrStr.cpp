//
//  StrStr.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "StrStr.h"

using namespace std;

void StrStr::run()
{
    cout<<"Run StrStr"<<endl;
    
    test2();
}

void StrStr::test1()
{
    char* haystack = "mississippi";
    char* needle = "issipi";
    
    char* result = strStr(haystack, needle);
    char* expected = NULL;
    
    assert(result == expected);
    
}

void StrStr::test2()
{
    char* haystack = "abcde";
    char* needle = "cd";
    
    char* result = strStr(haystack, needle);
    char* expected = haystack + 2;
    
    assert(result == expected);

    
}

void createPattern(const char* needle, vector<int>& pattern)
{
    size_t needleLength = strlen(needle);
    
    for (size_t i = 1; i < needleLength; ++i) {
        int p = pattern[i - 1];
        while (p != -1) {
            if (needle[p + 1] == needle[i]) {
                pattern[i] = p + 1;
                break;
            }
            else
                p = pattern[p];
        }
        
        // p == -1
        if (p == -1 && needle[0] == needle[i]) {
            pattern[i] = 0;
        }
    }
}

char* StrStr::strStr(char *haystack, char *needle)
{
    char* result = NULL;
    
    //Null pointer
    if (!haystack || !needle) {
        return result;
    }
    
    
    size_t hayLength = strlen(haystack);
    size_t needleLength = strlen(needle);
    
    if (needleLength > hayLength) {
        return result;
    }
    else if (hayLength == 0)
        return haystack;
    
    vector<int> pattern;
    pattern.assign(needleLength, -1);
    createPattern(needle, pattern);
    
    for (size_t i = 0; i < hayLength;) {
        
        bool equal = true;
        for (size_t j = 0; j < needleLength; ++j) {
            if (haystack[i + j] != needle[j]) {
                equal = false;
                if (j == 0 ) {
                    ++i;
                }
                else
                {
                    if (pattern[j-1] == -1) {
                        i += j - 1;
                    }
                    else
                        i += j - 1 - pattern[j - 1];
                }
                    
                break;
            }
        }
        
        if (equal) {
            return haystack + i;
        }

    }
    
    
    
    return result;
}


char* StrStr::strStr2(char *haystack, char *needle)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int nLen = strlen(needle);
    int* fail = new int[nLen];
    memset(fail, -1, nLen*sizeof(int));
    int i, j, k;
    for (i = 1; i < nLen; ++i)
    {
        for (k = fail[i-1]; k >= 0 && needle[i] != needle[k+1]; k = fail[k]);
        if (needle[k+1] == needle[i])
            fail[i] = k + 1;
    }
    i = j = 0;
    while(haystack[i] && needle[j])
    {
        if (haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else if(j == 0) ++i;
        else j = fail[j-1] + 1;
    }
    delete fail;
    if (needle[j]) return NULL;
    else return haystack + i - j;
}
