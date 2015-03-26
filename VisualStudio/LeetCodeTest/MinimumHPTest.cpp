#include "stdafx.h"
#include "CppUnitTest.h"
#include "MinimumHP.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(MinimumHPTest)
    {
    public:
        
        TEST_METHOD(testMinimumHP)
        {
            std::vector<std::vector<int>> board;

            int a1[] = {-2, -3, 3};
            int a2[] = {-5, -10, 1};
            int a3[] = {10, 30, -5};

            board.emplace_back(a1, a1 + sizeof(a1) / sizeof(*a1));
            board.emplace_back(a2, a2 + sizeof(a2) / sizeof(*a2));
            board.emplace_back(a3, a3 + sizeof(a3) / sizeof(*a3));

            int expected = 7;

            MinimumHP hp;
            int result = hp.calculateMinimumHP(board);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMinimumHPWith100)
        {
            std::vector<std::vector<int>> board;

            int a1[] = {100};

            board.emplace_back(a1, a1 + sizeof(a1) / sizeof(*a1));

            int expected = 1;

            MinimumHP hp;
            int result = hp.calculateMinimumHP(board);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMinimumHP2)
        {
            std::vector<std::vector<int>> board;

            int a1[] = {0, 0, 0};
            int a2[] = {1, 1, -1};

            board.emplace_back(a1, a1 + sizeof(a1) / sizeof(*a1));
            board.emplace_back(a2, a2 + sizeof(a2) / sizeof(*a2));

            int expected = 1;

            MinimumHP hp;
            int result = hp.calculateMinimumHP(board);

            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMinimumHP3)
        {
            std::vector<std::vector<int>> board;

            int a1[] = {1, -3, 3};
            int a2[] = {0, -2, 0};
            int a3[] = {-3, -3, -3};

            board.emplace_back(a1, a1 + sizeof(a1) / sizeof(*a1));
            board.emplace_back(a2, a2 + sizeof(a2) / sizeof(*a2));
            board.emplace_back(a3, a3 + sizeof(a3) / sizeof(*a3));

            int expected = 3;

            MinimumHP hp;
            int result = hp.calculateMinimumHP(board);

            Assert::IsTrue(result == expected);
        }

    };
}