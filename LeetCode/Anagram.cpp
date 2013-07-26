//
//  Anagram.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Anagram.h"
#include "ArrayUtil.h"

#include <map>

using namespace std;

void Anagram::run()
{
    cout<<"Run Anagram"<<endl;
    test1();
}

void Anagram::test1()
{
    string A[] = {"tea","and","ate","eat","dan"};
    int n = sizeof(A) / sizeof(*A);
    
    vector<string> strs = ArrayUtil::createFromArray(A, n);
    
    vector<string> result = anagrams(strs);
    
    assert(result.size() == 5);
    
}


vector<string> Anagram::anagrams(std::vector<std::string> &strs)
{
    map<string, vector<string> > anagramsMap;
    vector<string> result;

    for (size_t i = 0; i < strs.size(); ++i) {
        
        string s = strs[i];
        sort(s.begin(), s.end());
        if (anagramsMap.find(s) == anagramsMap.end()) {
            vector<string> value;
            value.push_back(strs[i]);
            anagramsMap[s] = value;
        }
        else {
            anagramsMap[s].push_back(strs[i]);
        }
    }
    
    map<string, vector<string> >::iterator it;
    for (it = anagramsMap.begin(); it != anagramsMap.end(); ++it) {
        if (it->second.size() > 1) {
            result.insert(result.end(), it->second.begin(), it->second.end());
        }
        
    }

    
    return result;
    
}