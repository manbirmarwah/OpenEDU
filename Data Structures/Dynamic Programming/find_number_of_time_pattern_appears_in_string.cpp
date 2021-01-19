#include <iostream>
using namespace std;

// Function to count number of times the pattern Y[0..n)
// appears in given string X[0..m) as a subsequence
int count(string X, string Y, int m, int n)
{
	// T[i][j] stores number of of times the pattern Y[0..j)
	// appears in given string X[0..i) as a subsequence
	int T[m + 1][n + 1];

	// if pattern Y is empty, we have found subsequence
	for (int i = 0; i <= m; i++)
		T[i][0] = 1;

	// if input string X is empty
	for (int j = 1; j <= n; j++)
		T[0][j] = 0;

	// if current character of both string and pattern matches,
	// 1. exclude current character in both string and pattern
	// 2. exclude only current character in the string

	// else if current character of string and pattern do not match,
	// exclude current character in the string

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			T[i][j] = ((X[i - 1] == Y[j - 1]) ? T[i - 1][j - 1] : 0) +
			          T[i - 1][j];

	// return last entry in lookup table
	return T[m][n];
}

int main()
{
	string X = "subsequence";	// input string
	string Y = "sue";			// pattern

	cout << count(X, Y, X.size(), Y.size()) << endl;

	return 0;
}