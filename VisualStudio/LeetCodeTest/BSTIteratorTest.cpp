#include "stdafx.h"
#include "CppUnitTest.h"
#include "BSTIterator.h"
#include "ListUtil.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(BSTIteratorTest)
    {
    public:
        
        TEST_METHOD(testBSTIterator)
        {
            int a[] = {1, 2, 3};
            int aSize = sizeof(a) / sizeof(*a);

            TreeNode* root = ListUtil::createTree(a, 0, aSize - 1);
            std::vector<int> expected(a, a + aSize);

            BSTIterator it(root);
            std::vector<int> result;

            while (it.hasNext())
            {
                result.push_back(it.next());
            }

            Assert::IsTrue(result == expected);
        }

    };
}