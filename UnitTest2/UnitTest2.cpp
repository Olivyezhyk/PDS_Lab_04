#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_04_02\LexPermutations.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestN5R3)
        {
            LexPermutations combinations("5", "3");
            vector<vector<int>> result = combinations.find();

            vector<vector<int>> expected = {
                {1, 2, 3},  {1, 2, 4},  {1, 2, 5},  {1, 3, 4},
                {1, 3, 5},  {1, 4, 5},  {2, 3, 4},
                {2, 3, 5},  {2, 4, 5},  {3, 4, 5}
            };

            Assert::AreEqual((int)expected.size(), (int)result.size(), L"Неправильна кількість перестановок для R=3");
            for (size_t i = 0; i < expected.size(); ++i) {
                for (size_t j = 0; j < expected[i].size(); ++j) {
                    wstring message = L"Неправильна перестановка на позиції " + to_wstring(i) + L", елемент " + to_wstring(j);
                    Assert::AreEqual(expected[i][j], result[i][j], message.c_str());
                }
            }
        }
    };
}