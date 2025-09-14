#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_04_01\LexPermutations.cpp"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestN3)
		{
			vector<vector<int>> expected = {
				{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
			};
			LexPermutations lexPerm("3");
			vector<vector<int>> result = lexPerm.find();
			Assert::AreEqual((int)expected.size(), (int)result.size(), L"Неправильна кількість перестановок для N=3");

			for (size_t i = 0; i < expected.size(); ++i) {
				for (size_t j = 0; j < expected[i].size(); ++j) {
					wstring message = L"Неправильна перестановка на позиції " + to_wstring(i) + L", елемент " + to_wstring(j);
					Assert::AreEqual(expected[i][j], result[i][j], message.c_str());
				}
			}
		}
	};
}