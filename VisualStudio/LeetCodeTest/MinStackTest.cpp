#include "stdafx.h"
#include "CppUnitTest.h"
#include "MinStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(MinStackTest)
    {
    public:
        
        TEST_METHOD(testMinStack)
        {
            MinStack s;

            s.push(3);
            s.push(2);
            s.push(1);

            Assert::IsTrue(s.getMin() == 1);
            Assert::IsTrue(s.top() == 1);
            s.pop();

            Assert::IsTrue(s.getMin() == 2);
            Assert::IsTrue(s.top() == 2);
        }

    };
}