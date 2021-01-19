#include <iostream>
#include <string>
using namespace std;

// define maximum possible length of string X and Y
#define M 20
#define N 25



// lookup[i][j] stores the length of LCS of substring X[0..i-1], Y[0..j-1]
int lookup[M][N];

// Function to display the differences between two strings
void diff(string X, string Y, int m, int n)
{
	// if last character of X and Y matches
	if (m > 0 && n > 0 && X[m - 1] == Y[n - 1])
	{
		diff(X, Y, m - 1, n - 1);
		cout << "  " << X[m - 1];
	}

	// current character of Y is not present in X
	else if (n > 0 && (m == 0 || lookup[m][n - 1] >= lookup[m - 1][n]))
	{
		diff(X, Y, m, n - 1);
		cout << " +" << Y[n - 1];
	}

	// current character of X is not present in Y
	else if (m > 0 && (n == 0 || lookup[m][n - 1] < lookup[m - 1][n]))
	{
		diff(X, Y, m - 1, n);
		cout << " -" << X[m - 1];
	}
}

// Function to fill lookup table by finding the length of LCS
// of substring X[0..m-1] and Y[0..n-1]
void lcs_length(string X, string Y, int m, int n)
{
	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			// else if current character of X and Y don't match
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
}

// Implement Diff Utility
int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif
	string X = "ABCDFGHJQZ";
	string Y = "ABCDEFGIJKRXYZ";
	int m = X.length(), n = Y.length();

	// fill lookup table
	lcs_length(X, Y, m, n);

	// find difference by reading lookup table in top-down manner
	diff(X, Y, m, n);

	return 0;
}