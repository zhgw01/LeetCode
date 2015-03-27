#pragma once
#include "stdafx.h"

class LEETCODE_API DNASequence :
    public IRun
{
public:
    DNASequence(void);
    ~DNASequence(void);

    std::vector<std::string> findRepeatedDnaSequences(std::string s);
};

