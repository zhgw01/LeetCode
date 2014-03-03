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
#include <string>

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

void WordLadderII::generatePath(const std::shared_ptr<NodeMap>& node, size_t index, vector<vector<string>>& result)
{
    if (!node) {
        return;
    }
    
    vector<string>& path = result[index];
    assert(path.size() > node->level);
    path[node->level] = node->word;
    

    for (size_t i = 0, iEnd = node->parents.size(); i < iEnd; ++i) {
        size_t next_index = index;
        
        if (i > 0) {
            result.push_back(vector<string>(path.begin(), path.end()));
            next_index = result.size() - 1;
        }
        
        generatePath(node->parents[i], next_index, result);
    }
    
}

vector<vector<string> > WordLadderII::findLadders(string start, string end, unordered_set<string> &dict)
{
    
    vector<vector<string>> result;
    
    if (start.size() != end.size() || start.empty() || end.empty()) {
        return result;
    }
    
    
    int level = 0;
    std::shared_ptr<NodeMap> root = std::make_shared<NodeMap>(start, level);
    std::shared_ptr<NodeMap> leaf = nullptr;
    
    std::queue<std::shared_ptr<NodeMap>> words;
    words.push(root);
    dict.erase(root->word);
    
    while (!words.empty() && !leaf) {
        size_t rowCount = words.size();
        ++level;
        
        vector<string> to_remove;
        std::unordered_map<string, shared_ptr<NodeMap>> wordMap;
        
        while (rowCount > 0) {
            std::shared_ptr<NodeMap> node = words.front();
            std::string word = node->word;
            words.pop();
            
            for (size_t i = 0, iEnd = word.size(); i < iEnd; ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    string temp = word;
                    temp[i] = c;
                    
                    if (temp == end) {
                        if (!leaf) {
                            leaf = std::make_shared<NodeMap>(end, level);
                        }

                        leaf->parents.push_back(node);
                    }
                    else if (dict.find(temp) != dict.end()) {
                        if (wordMap.find(temp) == wordMap.end()) {
                            wordMap[temp] = std::make_shared<NodeMap>(temp, level);
                            words.push(wordMap[temp]);
                        }
                        wordMap[temp]->parents.push_back(node);
                        to_remove.push_back(temp);
                    }
                }
            }
            
            --rowCount;
        }
        
        for_each(to_remove.begin(), to_remove.end(), [&dict](const string& s){
            dict.erase(s);
        });
        
    }
    
    //build the path
    if (leaf) {
        result.push_back(vector<string>(leaf->level + 1));
        generatePath(leaf, 0, result);
    }
    
    
    return result;
}

//DFS to find all the solution
void solveLadder(string start, string end,
                 unordered_set<string>& dict,
                 vector<string>& path,
                 vector<vector<string>>& paths,
                 unordered_map<string, size_t>& levelMap)
{
    //try to find results at start
    for (size_t i = 0, iEnd = start.length(); i < iEnd; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string next_word = start;
            
            if (next_word[i] != c) {
                next_word[i] = c;
                
                
                if (dict.find(next_word) != dict.end()) {
                    
                    if (levelMap.find(next_word) == levelMap.end()
                        || levelMap[next_word] != path.size() )
                        continue;
                    
                    path.push_back(next_word);
                    if (next_word == end)
                        paths.push_back(path);
                    else
                        solveLadder(next_word, end, dict, path, paths, levelMap);
                    path.pop_back();
                }
                else if (next_word == end) {
                    path.push_back(next_word);
                    paths.push_back(path);
                    path.pop_back();
                    
                }
                
                
            }
        }
    }
    
}

//BFS to build level map
void buildMap(string start, string end, unordered_set<string> dict, unordered_map<string, size_t>& levelMap)
{
    size_t levelCount = 0;
    queue<string> words;
    words.push(start);
    dict.erase(start);
    
    while (!words.empty()) {
        
        size_t rowNumber = words.size();
        
        //Iterator on current level
        for (size_t i = 0; i < rowNumber; ++i) {
            string& word = words.front();
            words.pop();
            levelMap[word] = levelCount;
            
            for (size_t j = 0, jEnd = word.length(); j < jEnd; ++j) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    string next = word;
                    next[j] = c;
                    
                    if (dict.find(next) != dict.end()) {
                        words.push(next);
                        dict.erase(next);
                    }
                }
            }
        }
        
        ++levelCount;
    }
}

//using backtracking
vector<vector<string> > WordLadderII::findLadders3(string start, string end, unordered_set<string> &dict)
{
    vector<vector<string>> result;
    
    if (start.size() != end.size() || start.empty() || end.empty()) {
        return result;
    }
    
    vector<string> path;
    path.push_back(start);
    dict.erase(start);
    std::unordered_map<string, size_t> levelMap;
    buildMap(start, end, dict, levelMap);
    solveLadder(start, end, dict, path, result, levelMap);
    
    return result;
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

vector<vector<string> > WordLadderII::findLadders2(string start, string end, unordered_set<string> &dict)
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