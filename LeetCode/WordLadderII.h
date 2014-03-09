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

struct GraphNode
{
    GraphNode(const std::string& w, int l) : word(w), level(l){}
    
    std::string word;
    int level;
    std::vector<GraphNode *> parents;
};

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
    
    
    GraphNode* createGraph(string start, string end, unordered_set<string>& dict,  vector<GraphNode*>& nodes);
    void generatePath( const GraphNode* const node, int index, vector<vector<string>>& result );
    

};

#endif /* defined(__LeetCode__WordLadderII__) */
