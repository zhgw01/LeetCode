//
//  MiniumWindow.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 8/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MiniumWindow.h"

using namespace std;

void MiniumWindow::run()
{
    cout<<"Run MiniumWindow"<<endl;
    
    test1();
}

void MiniumWindow::test1()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    
    string result = minWindow(S, T);
    string expected = "BANC";
    
    assert(result == expected);
}

void MiniumWindow::test2()
{
    string S = "bdab";
    string T = "ab";
    
    string result = minWindow(S, T);
    string expected = "ab";
    
    assert(result == expected);
}

bool equal(int* A, int* B, int n)
{
    for (int i = 0; i < n; ++i) {
        if (A[i] > B[i]) {
            return false;
        }
    }
    
    return true;
}

string MiniumWindow::minWindow(std::string S, std::string T)
{
    string result;
    
    if (T.empty()) {
        return result;
    }
    
    int needtoFind[256] = {0};
    int needCount = 0;
    for (int i = 0; i < T.size(); ++i) {
        ++needtoFind[T[i]];
        ++needCount;
    }
    
    int hasFound[256] = {0};
    
    int start = -1;
    for (int i = 0; i < S.size(); ++i) {
        if (needtoFind[S[i]]) {
            if (start == -1) {
                start = i;
            }
            
            ++hasFound[S[i]];
            
            if (equal(needtoFind, hasFound, 256)) {
                
                //find the minium
                while (hasFound[S[start]] > needtoFind[S[start]]) {
                    --hasFound[S[start]];
                    ++start;
                    while (needtoFind[S[start]] == 0) {
                        ++start;
                    }

                }
                
                int len = i - start + 1;
                string possibleSolution = S.substr(start, len);

                
                if (result.empty() || result.size() > possibleSolution.size()) {
                    result = possibleSolution;
                }
                
                
                //find the next start
                --hasFound[S[start]];
                ++start;
                while (needtoFind[S[start]] == 0) {
                    ++start;
                }

            }
        }
    }
    
    
    return result;
}