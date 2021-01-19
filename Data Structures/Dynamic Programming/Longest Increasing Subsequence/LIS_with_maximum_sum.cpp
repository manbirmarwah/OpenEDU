#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Iterative function to find maximum sum of an increasing subsequence
int MSIS(int arr[], int n)
{
	// array to store sub-problem solution. sum[i] stores the maximum
	// sum of the increasing subsequence that ends with arr[i]
	int sum[n] = { 0 };

	// base case
	sum[0] = arr[0];

	// start from second element in the array
	for (int i = 1; i < n; i++)
	{
		// do for each element in subarray arr[0..i-1]
		for (int j = 0; j < i; j++)
		{
			// find increasing subsequence with maximum sum that ends with
			// arr[j] where arr[j] is less than the current element arr[i]

			if (sum[i] < sum[j] && arr[i] > arr[j])
				sum[i] = sum[j];
		}

		// include arr[i] in MSIS
		sum[i] += arr[i];
	}

	// find increasing subsequence with maximum sum
	int msis = INT_MIN;
	for (int x : sum)
		msis = max(msis, x);

	return msis;
}

int main()
{
	int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum of increasing subsequence is " <<
	     MSIS(arr, n);

	return 0;
}