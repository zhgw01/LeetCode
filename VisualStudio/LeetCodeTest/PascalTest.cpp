#include "stdafx.h"
#include "LeetCode.h"
#include "CppUnitTest.h"
#include "Pascal.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LeetCodeTest
{
    TEST_CLASS(PascalTest)
    {
    public:
        
        TEST_METHOD(testGetRow)
        {
            Pascal p;

            vector<int> firstRow = p.getRow(0);

            Assert::IsTrue(firstRow.size() == 1);
        }

    };
}