//
//  WordBreakII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "WordBreakII.h"

using namespace std;

void WordBreakII::run()
{
    cout<<"Run WordBreakII"<<endl;
    test1();
}

void WordBreakII::test1()
{
    string s = "ab";
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("b");
    
    vector<string> result = wordBreak(s, dict);
    assert(result.size() == 1);
}

vector<string> WordBreakII::getWords( int n, const vector<bool> &canBreak, const string& s, unordered_set<string> &dict)
{
    vector<string> result;
    
    if (canBreak[n]) {
        for (int i = 0 ; i < n; ++i) {
            
            string sub = s.substr(i, n - i);
            if (canBreak[i] && dict.find(sub) != dict.end()) {
                if (i == 0) {
                    result.push_back(sub);
                }
                else {
                    vector<string> subResult = getWords(i, canBreak, s, dict);
                    for (string prefix : subResult) {
                        result.push_back(prefix + " " + sub);
                    }
                }
            }
        }
    }
    
    return result;
}

vector<string> WordBreakII::wordBreak(string s, unordered_set<string> &dict)
{
    
    vector<string> result;
    
    if (s.empty() || dict.empty()) {
        return result;
    }
    
    vector<bool> canBreak(s.length() + 1, false);
    canBreak[0] = true;
    
    for (int i = 1; i <= s.length(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            string sub = s.substr(j, i-j);
            if (canBreak[j] && dict.find(sub) != dict.end()) {
                canBreak[i] = true;
                break;
                
            }
        }
    }
    
    result = getWords(s.length(), canBreak, s, dict);

    return result;
}