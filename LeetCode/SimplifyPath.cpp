//
//  SimplifyPath.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "SimplifyPath.h"

using namespace std;

void SimplifyPath::run()
{
    cout<<"Run SimplifyPath"<<endl;
    test1();
}

void SimplifyPath::test1()
{
    string path = "/a/./b/../../c/";
    
    string result = simplifyPath(path);
    string expected = "/c";
    
    assert(result == expected);
}


string SimplifyPath::simplifyPath(std::string path)
{
    
    if (path.size() <= 1) {
        return path;
    }
    
    string result;
    vector<string> pathStack;
    
   
    int index = 1;
    while (index < path.size()) {
        int nextIndex = path.find('/', index);
        int len = nextIndex - index;
        string currentPath = path.substr(index, len);
        
        if (!currentPath.empty() && currentPath != ".") {
            if (currentPath == "..") {
                if (!pathStack.empty()) {
                    pathStack.pop_back();
                }
            }
            else
                pathStack.push_back(currentPath);
        }
        
        if (nextIndex == string::npos) {
            break;
        }
        else
            index = nextIndex + 1;
    }
   
    for (size_t i = 0; i < pathStack.size(); ++i) {
        result += "/" + pathStack[i];
    }
    
    if (result.empty() && !path.empty()) {
        result =  "/";
    }
    
    return result;
}