//
//  WordBreak.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/21/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "WordBreak.h"

using namespace std;

void WordBreak::run()
{
    cout<<"Run WordBreak"<<endl;
    test1();
}

void WordBreak::test1()
{
    string s = "a";
    unordered_set<string> dict;
    dict.insert("b");
    
    bool result = wordBreak(s, dict);
    assert(result == false);
}


bool WordBreak::wordBreak(string s, unordered_set<string> &dict)
{
    vector<bool> canBreak(s.length() + 1, false);
    canBreak[0] = true;
    
    for (int i = 1; i <= s.length(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (canBreak[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                canBreak[i] = true;
                break;
            }
        }
    }
    
    return canBreak[s.length()];
}