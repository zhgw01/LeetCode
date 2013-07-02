//
//  ConCatWords.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "ConCatWords.h"
#include <map>

using namespace std;

void ConCatWords::run()
{
    cout<<"Run ConCatWords"<<endl;
    test2();
}

void ConCatWords::test1()
{
    string s = "barfoothefoobarman";
    vector<string> l;
    l.push_back("foo");
    l.push_back("bar");
    
    
    
    vector<int> result = findSubstring(s, l);
    assert(result.size() == 2);
    assert(result[0] == 0);
    assert(result[1] == 9);
    
}

void ConCatWords::test2()
{
    string s = "a";
    vector<string> l;
    l.push_back("a");
    
    
    
    vector<int> result = findSubstring(s, l);
    assert(result.size() == 1);


}


vector<int> ConCatWords::findSubstring(std::string S, std::vector<std::string> &L)
{
    vector<int> result;
    if (L.size() == 0 || S.empty()) {
        return result;
    }
    
    map<string, int> words;
    for (size_t i = 0; i < L.size(); ++i) {
        ++words[L[i]];
    }
    
    map<string, int> curString;
    size_t N = L.size();
    size_t M = L[0].size();

    int end = S.size() - N*M;
    
    for (int i = 0; i <= end; ++i) {
        curString.clear();
        
        size_t j;
        for (j = 0; j < N; ++j) {
            string word = S.substr(i + j*M, M);
            
            if (words.find(word) == words.end()) {
                break;
            }
            
            ++curString[word];
            
            if (curString[word] > words[word]) {
                break;
            }
        }
        
        if (j == N) {
            result.push_back(i);
        }
        
        
    }
    
    
    
    
    
    return result;
}