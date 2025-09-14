#include "LexPermutations.h"
#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long LexPermutations::getFactorial(unsigned int N) {
    if (N == 0) return 1;
    return N * getFactorial(N - 1);
}

void LexPermutations::Input() {
    string N;
    do {
        try {
            cout << "Enter the number of elements in the set as a natural number: ";
            getline(cin, N);
            if (stol(N) <= 0) {
                cout << "The number of elements was entered incorrectly." << endl;
                continue;
            }
            this->N = stoul(N);
            cout << "The set was successfully defined." << endl;
        }
        catch (const std::invalid_argument&) {
            cerr << "Invalid numeric input, please try again." << endl;
            continue;
        }
        break;
    } while (true);
}

void LexPermutations::printLowestPerm() {
    cout << "The smallest permutation of the set elements: {";
    for (size_t i = 1; i < this->N; i++)
        cout << i << ", ";
    cout << this->N << "}." << endl;
}

vector<vector<int>> LexPermutations::find() {
    vector<vector<int>> permutations;
    vector<int> permutation = vector<int>(this->N);

    for (int i = 0; i < this->N; i++)
        permutation[i] = i + 1;

    cout << "i = " << 1 << "\t{";
    for (int i = 0; i < this->N - 1; i++)
        cout << permutation[i] << ", ";
    cout << permutation[this->N - 1] << "}." << endl;

    permutations.push_back(permutation);

    for (size_t i = 1; i < getFactorial(this->N); i++) {
        int j = this->N - 2;

        while (j >= 0 && permutation[j] >= permutation[j + 1]) {
            j--;
        }
        if (j < 0) {
            break;
        }

        int k = this->N - 1;
        while (permutation[k] <= permutation[j]) {
            k--;
        }

        swap(permutation[j], permutation[k]);

        reverse(permutation.begin() + j + 1, permutation.end());

        cout << "i = " << i + 1 << "\t{";
        for (int l = 0; l < this->N - 1; l++) {
            cout << permutation[l] << ", ";
        }
        cout << permutation[this->N - 1] << "}." << endl;
        permutations.push_back(permutation);
    }
    return permutations;
};

LexPermutations::LexPermutations(string N) {
    if (stol(N) <= 0) {
        this->Input();
    }
    else
        this->N = stoul(N);
};
