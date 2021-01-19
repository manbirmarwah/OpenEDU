// A Dynamic Programming solution 
// for subset sum problem 
#include <bits/stdc++.h>

using namespace std;

// Returns true if there is a subset of set[] 
// with sun equal to given sum 
int isSubsetSum(int set[], int n, int sum) 
{ 
	// The value of subset[i][j] will be true if 
	// there is a subset of set[0..j-1] with sum 
	// equal to i 
	int subset[n + 1][sum + 1]; 

	// If sum is 0, then answer is true 
	for (int i = 0; i <= n; i++) 
		subset[i][0] = true; 

	// If sum is not 0 and set is empty, 
	// then answer is false 
	for (int i = 1; i <= sum; i++) 
		subset[0][i] = false; 

	// Fill the subset table in botton up manner 
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= sum; j++) { 
			if (j < set[i - 1]) 
				subset[i][j] = subset[i - 1][j]; 
			if (j >= set[i - 1]) 
				subset[i][j] = subset[i - 1][j] 
							+ subset[i - 1][j - set[i - 1]]; 
		} 
	} 

	/* // uncomment this code to print table 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= sum; j++) 
		printf ("%4d", subset[i][j]); 
	printf("\n"); 
	}*/

	return subset[n][sum]; 
} 

// Driver program to test above function 
int main() 
{ 
	int set[] = { 2, 3, 5, 8, 10}; 
	int sum = 10; 
	int n = sizeof(set) / sizeof(set[0]); 
	cout<<isSubsetSum(set, n, sum)<<endl; 
		
	
	return 0; 
} 
// This code is contributed by Arjun Tyagi. 
