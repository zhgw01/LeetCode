//
//  WordLadder.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "WordLadder.h"
#include <queue>

using namespace std;

void WordLadder::run()
{
    cout<<"Run WordLadder"<<endl;
    test1();
}

void WordLadder::test1()
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    
    string start = "hit";
    string end = "cog";
    
    int result = ladderLength(start, end, dict);
    
    assert(result == 5);
}


//Using BFS to find
int WordLadder::ladderLength(std::string start, std::string end, std::unordered_set<std::string> &dict)
{
    if (start.size() != end.size()) {
        return 0;
    }
    
    if (start.empty() || end.empty()) {
        return 0;
    }
    
    if (dict.size() == 0) {
        return 0;
    }
    
    int result = 0;
    
    queue<string> words;
    words.push(start);
        
    
    //level travel
    while (!words.empty()) {
        
        int levelCount = words.size();
        
        while (levelCount > 0) {
            string str = words.front();
            words.pop();
            
            //try to transform on distance 1
            for (int i = 0 ; i < str.size(); ++i) {
                for (int j = 'a'; j <'z'; ++j) {
                    
                    string temp = str;
                    temp[i] = j;
                    
                    if (temp == end) {
                        return result + 2;
                    }
                    
                    if (dict.find(temp) != dict.end()) {
                        words.push(temp);
                        dict.erase(temp);
                    }
                }
            }
            
            
            --levelCount;
        }
        
        ++result;
        
    }
    
    return 0;
}