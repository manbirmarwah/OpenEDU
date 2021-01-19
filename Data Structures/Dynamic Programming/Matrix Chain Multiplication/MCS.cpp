#include<bits/stdc++.h>
using namespace std;

int tdp[5][5];//size of array + 1

int MCS(int m[], int i, int j)
{
    if(i == j)
    {
        tdp[i][j] = 0;
        return 0;
    }

    if(tdp[i][j] != -1)
    return tdp[i][j];
    
    int ans = INT_MAX;
    for(int k=i ; k<j ; k++)
    {
        int tempAns = MCS(m, i, k) + MCS(m, k+1, j) + (m[i-1]*m[k]*m[j]);

        ans = min(ans, tempAns);

    }
    return tdp[i][j] = ans;
}

int main()
{
    memset(tdp, -1, sizeof(tdp));
    int matrices[] = {1, 2, 3, 4};

    int n = sizeof(matrices)/sizeof(int);
    

    cout<<MCS(matrices, 1, n-1)<<endl;
    return 0;
}