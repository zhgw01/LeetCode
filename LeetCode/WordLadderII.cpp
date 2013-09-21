//
//  WordLadderII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "WordLadderII.h"
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

void WordLadderII::run()
{
    cout<<"Run WordLadderII"<<endl;
    test3();
}

void WordLadderII::test1()
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dog");
    dict.insert("dot");

    
    string start = "hot";
    string end = "dog";
    
    vector<vector<string> > result = findLadders(start, end, dict);
    
    assert(result.size() == 1);

}

void WordLadderII::test2()
{
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");
    
    
    string start = "a";
    string end = "c";
    
    vector<vector<string> > result = findLadders(start, end, dict);
    
    assert(result.size() == 1);
    
}

void WordLadderII::test3()
{
    unordered_set<string> dict;
    dict.insert("ted");
    dict.insert("tex");
    dict.insert("red");
    dict.insert("tax");
    dict.insert("tad");
    dict.insert("den");
    dict.insert("rex");
    dict.insert("pee");
    
    
    string start = "red";
    string end = "tax";
    
    vector<vector<string> > result = findLadders(start, end, dict);
    
    assert(result.size() == 3);

}


vector<vector<string> > buildPath(const unordered_map<string, set<string> > & pathMap, const string& end, const string& start)
{
    vector<vector<string> > paths;
  
    if (end == start) {
        vector<string> prev;
        prev.push_back(start);
        paths.push_back(prev);
        
        return paths;
    }
    
    if (pathMap.find(end) != pathMap.end()) {
        set<string> prev = pathMap.at(end);
        set<string>::const_iterator it = prev.begin();
        
        for (; it != prev.end(); ++it) {
            string str = *it;
            vector<vector<string> > result = buildPath(pathMap, *it, start);
            paths.insert(paths.end(), result.begin(), result.end());
        }
    }
    
    vector<vector<string> >::iterator resultIt = paths.begin();
    for (; resultIt != paths.end(); ++resultIt) {
    
        resultIt->push_back(end);
    }
    
    return  paths;
}

vector<vector<string> > WordLadderII::findLadders(string start, string end, unordered_set<string> &dict)
{
    vector<vector<string> > result;
    
    if (start.size() != end.size()) {
        return result;
    }
    
    if (start.empty() || end.empty()) {
        return result;
    }
    

    unordered_map<string, set<string> > pathMap;
    
    queue<string> words;
    words.push(start);
    
    bool stopLevel = false;
    while (!words.empty() && !stopLevel) {
        
        int levelCount = words.size();
        vector<string> toRemove;
        
        while (levelCount > 0) {
            string str = words.front();
            words.pop();
            

        
            for (int i = 0; i < str.size(); ++i) {
                for (int j = 'a'; j <= 'z'; ++j) {
                    string temp = str;
                    temp[i] = j;
                    
                    if (temp == end) {
                        stopLevel = true;
                        pathMap[temp].insert(str);
                        continue;
                    }
                    
                    if (dict.find(temp) != dict.end()) {
                        //possible solution
                        pathMap[temp].insert(str);
                        
                        toRemove.push_back(temp);
                        words.push(temp);
                    }
                    
                }
            }
            
            --levelCount;
        }
        
        for (int i = 0; i < toRemove.size(); ++i) {
            dict.erase(toRemove[i]);
        }
        
    }
    
    
    return buildPath(pathMap, end, start);
    
}