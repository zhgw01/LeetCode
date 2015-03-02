#include "stdafx.h"
#include "WordLadderII.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;


void WordLadderII::run()
{
    cout<<"Run WordLadder"<<endl;
    //test();
    //test2();
    test3();
}

void WordLadderII::test()
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dog");
    dict.insert("cog");
    dict.insert("pot");
    dict.insert("dot");



    string start = "hot";
    string end = "dog";

    vector<vector<string>> result = findLadders(start, end, dict);

    assert(result.size() > 0);
}

vector<vector<string>> WordLadderII::findLadders( string start, string end, unordered_set<string> &dict )
{
    vector<vector<string>> result;


    if (start.size() != end.size() || start.empty())
        return result;

    vector<GraphNode*> nodes;
    GraphNode* root = createGraph(start, end, dict, nodes);

    if (root)
    {
        vector<string> path(root->level + 1);
        result.push_back(path);
        buildPath(root, 0, result);

        for_each(nodes.begin(), nodes.end(), [](GraphNode* node){
            delete node;
        });
    }

    return result;
}

GraphNode* WordLadderII::createGraph(string start, string end, unordered_set<string>& dict,  vector<GraphNode*>& nodes)
{
    dict.erase(start);
    dict.erase(end);

    int level = 0;
    GraphNode* startNode = new GraphNode(start, level);
    GraphNode* endNode = nullptr;

    //BFS search
    queue<GraphNode*> row;
    row.push(startNode);

    while (!row.empty() && !endNode)
    {
        size_t rowCount = row.size();

        ++level;
        vector<string> to_remove;
        unordered_map<string, GraphNode*> word_node;
        while (rowCount-- >  0)
        {
            GraphNode* node = row.front();
            row.pop();
            string word = node->word;

            for (int i = 0, iEnd = word.size(); i < iEnd; ++i)
            {
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (word[i] != c)
                    {
                        //generate a new word
                        string temp = word;
                        temp[i] = c;

                        if (temp == end)
                        {
                            if (!endNode) {
                                endNode = new GraphNode(end, level);
                                nodes.push_back(endNode);
                            }

                            endNode->parents.push_back(node);
                        }
                        //possible solution
                         else if (dict.find(temp) != dict.end())
                        {
                            if (word_node.find(temp) == word_node.end())
                            {
                                GraphNode* new_node = new GraphNode(temp, level);
                                nodes.push_back(new_node);

                                word_node[temp] = new_node;
                                row.push(new_node);
                                to_remove.push_back(temp);
                            }

                            word_node[temp]->parents.push_back(node);
                        }

                    }
                }
            }
        }

        //remove visited items in current row from  dictionary
        for_each(to_remove.begin(), to_remove.end(), [&dict](const string& item){
            dict.erase(item);
        });

    }

    return endNode;
}

void WordLadderII::buildPath( const GraphNode* const node, int index, vector<vector<string>>& result )
{
    if (!node)
        return;

    result[index][node->level] = node->word;

    for (size_t i = 0, iEnd = node->parents.size(); i < iEnd; ++i)
    {
        int next_index = index;

        if (i > 0)
        {
            result.push_back(result[index]);
            next_index = result.size() - 1;
        }

        buildPath(node->parents[i], next_index, result);
    }
}

void WordLadderII::test2()
{
    unordered_set<string> dict;

    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    string start = "hit";
    string end = "cog";

    vector<vector<string>> result = findLadders(start, end, dict);

    assert(result.size() == 2);
}

void WordLadderII::test3()
{
    unordered_set<string> dict;

    dict.insert("ts");
    dict.insert("sc");
    dict.insert("ph");
    dict.insert("ca");
    dict.insert("jr");
    dict.insert("hf");
    dict.insert("to");
    dict.insert("if");
    dict.insert("ha");
    dict.insert("is");
    dict.insert("io");
    dict.insert("cf");
    dict.insert("ta");

    string start = "ta";
    string end = "if";

    vector<vector<string>> result = findLadders(start, end, dict);

    assert(result.size() == 4);
}
