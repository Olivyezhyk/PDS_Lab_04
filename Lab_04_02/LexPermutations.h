#pragma once

#include <string>
#include <vector>

using namespace std;

class LexPermutations {
private:
	unsigned int N, R;
	unsigned long long getFactorial(unsigned int N);
	bool nextCombination(vector<int>& permutation);
public:
	void Input();

	void printLowestPerm();
	vector<vector<int>> find();

	LexPermutations() { Input(); };
	LexPermutations(string N, string R);
};