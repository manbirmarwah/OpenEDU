#include <iostream>
using namespace std;

// Function to count total number of possible solutions of a
// linear equation of k variables
int count(int coeff[], int k, int rhs)
{
	// if rhs becomes 0, return 1 (solution found)
	if (rhs == 0)
		return 1;

	// return 0 (solution do not exist) if rhs becomes negative or
	// no coefficient is left
	if (rhs < 0 || k < 0)
		return 0;

	// Case 1. include current coefficient coeff[k] in solution and
	// recur with remaining value (rhs - coeff[k])

	int include = count(coeff, k, rhs - coeff[k]);

	// Case 2. exclude current coefficient coeff[k] from solution and
	// recur for remaining coefficients (k - 1)

	int exclude = count(coeff, k - 1, rhs);

	// return total ways by including or excluding current coefficient
	return include + exclude;
}

int main()
{
	// k coefficients of given equation
	int coeff[] = { 1, 2, 3 };
	int k = sizeof(coeff) / sizeof(coeff[0]);

	int rhs = 4;

	cout << "Total number of solutions are " << count(coeff, k - 1, rhs);

	return 0;
}