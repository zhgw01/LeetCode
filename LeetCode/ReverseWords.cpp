//
//  ReverseWords.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 3/9/14.
//  Copyright (c) 2014 Zhang Gongwei. All rights reserved.
//

#include "ReverseWords.h"

using namespace std;

void ReverseWords::run()
{
    cout<<"Run ReverseWords"<<endl;
    test3();
}

void ReverseWords::test1()
{
    string s = "the sky is blue";
    string expected = "blue is sky the";
    
    reverseWords(s);
    assert(s == expected);
}

void ReverseWords::test2()
{
    string s = " ";
    string expected;
    
    reverseWords(s);
    assert(s == expected);
}

void ReverseWords::test3()
{
    string s = "1 ";
    string expected = "1";
    
    reverseWords(s);
    assert(s == expected);
    
}

void reverseWord(std::string& w, size_t start, size_t end)
{
    if (start == end)
        return;
    
    --end;
    while (start < end) {
        swap(w[start], w[end]);
        
        ++start;
        --end;
    }
}

void ReverseWords::reverseWords(std::string& s)
{
    
    size_t next = 0;
    size_t end = s.size();
    
    size_t word_start = 0;
    size_t word_end = 0;
    while (next < end) {
        //check next word;
        while (next < end && isspace(s[next]))
            ++next;
        
        //start next word
        if (word_start != 0 && next < end) {
            s[word_start++] = ' ';
        }
        
        word_end = word_start;
        while (next < end && !isspace(s[next])) {
            s[word_end++] = s[next++];
        }
        
        reverseWord(s, word_start, word_end);
        word_start = word_end;
    }
    
    s.resize(word_end);
    reverseWord(s, 0, word_end);
    
}
