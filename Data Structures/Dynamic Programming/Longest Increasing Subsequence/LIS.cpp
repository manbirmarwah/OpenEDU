#include<bits/stdc++.h>


using namespace std;

int lis(int input[], int n)
{
	int out[n + 1];
	out[0] = 1;
	for (int i = 1 ; i < n ; i++)
	{
		out[i] = 1;
		for (int j = i - 1 ; j >= 0 ; j--)
		{
			if (input[j] > input[i])
				continue;
			int possibleAns = out[j] + 1;

			if (possibleAns > out[i])
				out[i] = possibleAns;

		}
	}

	int ans = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (out[i] > ans)
			ans = out[i];

	}
	// out.clear();
	return ans;

}

int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif
	int n;
	cin >> n;
	int input[n + 1];

	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	cout << lis(input, n) << endl;

	// input.clear();
	return 0;
}