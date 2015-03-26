#include "stdafx.h"
#include "CppUnitTest.h"
#include "TrailingZero.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(TrailingZeroTest)
    {
    public:
        
        TEST_METHOD(testTrailingZero)
        {
            int n = 5;
            int expected = 1;

            TrailingZero factorial;
            int result = factorial.trailingZeroes(n);

            Assert::IsTrue(result == expected);
        }

    };
}