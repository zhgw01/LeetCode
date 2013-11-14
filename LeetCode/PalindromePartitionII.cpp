//
//  PalindromePartitionII.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/13/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "PalindromePartitionII.h"

using namespace std;

void PalindromePartitionII::run()
{
    cout<<"Run PalindromePartitionII"<<endl;
    
    test2();
}

void PalindromePartitionII::test1()
{
    string s = "adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";
    
    int result = minCut(s);
    
    assert(result == 273);
}

void PalindromePartitionII::test2() {
    string s = "bb";
    
    int result = minCut(s);
    
    assert(result == 0);
}


int PalindromePartitionII::minCut(std::string s)
{
    if (s.size() < 2) {
        return 0;
    }

    size_t n = s.size();
    int cut[n+1];
    bool palindrome[n][n];
   
    //Initialize, based on the length: n
    for (size_t i = 0; i <= n; ++i) {
        cut[i] = static_cast<int>(n - i) - 1;
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0 ; j < n; ++j) {
            palindrome[i][j] = false;
        }
    }
    
    //update cut[i] iterately from s[n-1] to s[0]
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i; j <= n - 1; ++j) {
            
            bool innerPalindrome = ((j-i) < 2) || palindrome[i+1][j-1];
            
            if ((s[i] == s[j]) && innerPalindrome) {
                palindrome[i][j] = true;
                cut[i] = min(cut[i], cut[j+1] + 1);
            }
        }
    }
    
    return cut[0];
}