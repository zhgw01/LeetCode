//
//  PhoneNumber.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 6/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PhoneNumber.h"

#include <stack>

using namespace std;

void PhoneNumber::run()
{
    cout<<"Run Phone Number"<<endl;
    test2();
}

void PhoneNumber::test1()
{
    string digits = "23";
    
    vector<string> result = letterCombinations(digits);
    
    assert(result.size() == 9);
}

void PhoneNumber::test2()
{
    string digits = "";
    
    vector<string> result = letterCombinations(digits);
    
    assert(result.size() == 1);
   
}

string getmapping(char digit)
{
    switch (digit) {
        case '0':
            return " ";
            
        case '1':
            return "1";
            
        case '2':
            return "abc";
            
        case '3':
            return "def";
            
        case '4':
            return "ghi";
            
        case '5':
            return "jkl";
            
        case '6':
            return "mno";
            
        case '7':
            return "pqrs";
            
        case '8':
            return "tuv";
            
        case '9':
            return "wxyz";
            
        default:
            return "";
    }
}

vector<string> PhoneNumber::letterCombinations(const std::string &digits)
{
    vector<string> result;
 
    if (digits.empty()) {
        result.push_back("");
        return result;
    }
    
    struct mapCount
    {
        string map;
        size_t i;
        size_t digitIndex;
    };
    
    stack<mapCount> mapStack;
    
    mapCount head;
    head.map = getmapping(digits[0]);
    head.i = 0;
    head.digitIndex = 0;
    mapStack.push(head);
    
    string s;
    s.resize(digits.size());
    while (!mapStack.empty()) {
        mapCount& currrent = mapStack.top();
        if (currrent.i < currrent.map.size()) {
            s[currrent.digitIndex] = currrent.map[currrent.i++];
            if (currrent.digitIndex == digits.size() - 1) {
                //copy the string
                result.push_back(s);
            }
            else {
                mapCount node;
                node.i = 0;
                node.digitIndex = currrent.digitIndex + 1;
                node.map = getmapping(digits[node.digitIndex]);
                mapStack.push(node);
            }
        }
        else
            mapStack.pop();
    }
    
    
    return result;
}