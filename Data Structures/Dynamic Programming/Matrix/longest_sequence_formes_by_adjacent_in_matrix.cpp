#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// N x N matrix
#define N 5

// Function to check if cell (i, j) is a valid cell or not
bool isValid(int i, int j)
{
	return (i >= 0 && i < N && j >= 0 && j < N);
}

// Find longest path starting from cell (i, j) formed by adjacent
// numbers in the matrix
string findLongestPath(int mat[N][N], int i, int j)
{
	// if the cell is invalid
	if (!isValid (i, j))
		return 0;

	// string to store path starting (i, j)
	string path;

	// recur top cell if its value is +1 of value at (i, j)
	if (i > 0 && mat[i - 1][j] - mat[i][j] == 1)
		path = findLongestPath(mat, i - 1, j);

	// recur right cell if its value is +1 of value at (i, j)
	if (j + 1 < N && mat[i][j + 1] - mat[i][j] == 1)
		path = findLongestPath(mat, i, j + 1);

	// recur bottom cell if its value is +1 of value at (i, j)
	if (i + 1 < N && mat[i + 1][j] - mat[i][j] == 1)
		path = findLongestPath(mat, i + 1, j);

	// recur left cell if its value is +1 of value at (i, j)
	if (j > 0 && mat[i][j - 1] - mat[i][j] == 1)
		path = findLongestPath(mat, i, j - 1);

	// note that as matrix contains all distinct elements,
	// there is only one path possible from current cell

	// return path starting from (i, j)
	return to_string(mat[i][j]) + " - " +  path;
}

int main()
{
	int mat[N][N] =
	{
		{ 10, 13, 14, 21, 23 },
		{ 11,  9, 22,  2,  3 },
		{ 12,  8,  1,  5,  4 },
		{ 15, 24,  7,  6, 20 },
		{ 16, 17, 18, 19, 25 }
	};

	string res;				// stores longest path found so far
	string str;				// stores current path
	int resSize = INT_MIN;	// stores no. of elements in res

	// from each cell (i, j), find the longest path starting from it
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// str would be like 1 - 2 - 3 - 4 - 5 -
			string str = findLongestPath(mat, i, j);

			// find number of elements involved in current path
			int size = count(str.begin(), str.end(), '-');

			// update result if longer path is found
			if (size > resSize)
				res = str, resSize = size;
		}
	}

	// print the path
	cout << res.substr(0, res.length() - 3);

	return 0;
}