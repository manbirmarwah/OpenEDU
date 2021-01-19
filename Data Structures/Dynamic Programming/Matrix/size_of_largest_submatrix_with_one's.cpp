#include <iostream>
using namespace std;

// M x N matrix
#define M 8
#define N 6

// Function to find the size of largest square sub-matrix of 1's
// present in the given binary matrix
int findLargestSquare(int mat[M][N])
{
	// lookup[i][j] stores the size of maximum square
	// sub-matrix ending at mat[i][j]
	int lookup[M][N];

	// max stores the size of largest square sub-matrix of 1's
	int max = 0;

	// fill in bottom-up manner
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			lookup[i][j] = mat[i][j];

			// if we are not at the first row or first column and
			// current cell has value 1
			if (i && j && mat[i][j])

				// largest square sub-matrix ending at mat[i][j] will be
				// 1 plus minimum of largest square sub-matrix ending at
				// mat[i][j-1], mat[i-1][j] and mat[i-1][j-1]

				lookup[i][j] = min (min (lookup[i][j - 1], lookup[i - 1][j]),
				                    lookup[i - 1][j - 1]) + 1;

			// update maximum size found so far
			if (max < lookup[i][j])
				max = lookup[i][j];
		}
	}

	// return size of largest square matrix
	return max;
}

int main()
{
	// input boolean matrix
	int mat[M][N] =
	{
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	cout << "The size of largest square sub-matrix of 1's is " <<
	     findLargestSquare(mat);

	return 0;
}