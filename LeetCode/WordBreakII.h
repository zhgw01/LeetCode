//
//  WordBreakII.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__WordBreakII__
#define __LeetCode__WordBreakII__

#include "IRun.h"
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class WordBreakII : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    vector<string> wordBreak(string s, unordered_set<string> &dict);
    vector<string> getWords(int i, const vector<bool>& canBreak, const string& s, unordered_set<string> &dict);

};

#endif /* defined(__LeetCode__WordBreakII__) */
