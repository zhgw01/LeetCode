//
//  WordLadderII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 9/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__WordLadderII__
#define __LeetCode__WordLadderII__

#include "IRun.h"

#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;

class WordLadderII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    void test2();
    void test3();
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict);
    vector<vector<string>> findLadders2(string start, string end, unordered_set<string> &dict);
    vector<vector<string>> findLadders3(string start, string end, unordered_set<string> &dict);
    
    
    struct NodeMap {
        string word;
        int level;
        vector<std::shared_ptr<NodeMap>> parents;
        
        NodeMap(const string& w, int l) : word(w), level(l) {}
    };

    void generatePath(const std::shared_ptr<NodeMap>& node, size_t index, vector<vector<string>>& result);

};

#endif /* defined(__LeetCode__WordLadderII__) */
