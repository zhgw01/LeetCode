#pragma once
#include "irun.h"

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct GraphNode
{
    GraphNode(const string& w, int l) : word(w), level(l){}

    string word;
    int level;
    vector<GraphNode *> parents;
};

class WordLadderII :
    public IRun
{
public:
    virtual void run();

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict);

private:
    void test();
    void test2();
    void test3();

    GraphNode* createGraph(string start, string end, unordered_set<string>& dict, vector<GraphNode*>& nodes);
    void buildPath(const GraphNode* const node, int index, vector<vector<string>>& result);

};

