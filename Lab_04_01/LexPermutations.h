#pragma once

#include <string>
#include <vector>

using namespace std;

class LexPermutations {
private:
	unsigned int N;
	unsigned long long getFactorial(unsigned int N);
public:
	void Input();

	void printLowestPerm();
	vector<vector<int>> find();

	LexPermutations() { Input(); };
	LexPermutations(string N);
};