#include <iostream>
#include<cstring>
using namespace std;

// Function to find Levenshtein Distance between string X and Y
// m and n are the number of characters in X and Y respectively
int dist(string X, int m, string Y, int n)
{
	// for all i and j, T[i,j] will hold the Levenshtein distance between
	// the first i characters of X and the first j characters of Y
	// note that T has (m+1)*(n+1) values

	int T[m + 1][n + 1] = { 0 };

	// source prefixes can be transformed into empty string by
	// dropping all characters

	for (int i = 1; i <= m; i++)
		T[i][0] = i;				// (case 1)

	// target prefixes can be reached from empty source prefix
	// by inserting every character

	for (int j = 1; j <= n; j++)
		T[0][j] = j;				// (case 1)

	int substitutionCost;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])   			 // (case 2)
				substitutionCost = 0;   			 // (case 2)
			else
				substitutionCost = 1;   			 // (case 3c)

			T[i][j] = min(min(T[i - 1][j] + 1,	   // deletion (case 3b)
			                  T[i][j - 1] + 1),	  // insertion (case 3a)
			              T[i - 1][j - 1] + substitutionCost); // replace (case 2 & 3c)
		}
	}

	return T[m][n];
}

int main()
{
	string X = "kitten", Y = "sitting";

	cout << "The Levenshtein Distance is " <<
	     dist(X, X.length(), Y, Y.length());

	return 0;
}