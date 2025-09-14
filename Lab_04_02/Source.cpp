#include"LexPermutations.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LexPermutations lex;
	lex.printLowestPerm();
	lex.find();
}