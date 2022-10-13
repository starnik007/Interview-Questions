#include <bits/stdc++.h>
using namespace std;

vector<int> dp(4010);
int mS(int i, int a, int b, int c)
{
    if (i == 0)
        return 0;
    if (dp[i] != INT_MIN)
        return dp[i];

    int ans = INT_MIN;
    if (i - a >= 0)
        ans = mS(i - a, a, b, c) + 1;
    if (i - b >= 0)
        ans = max(ans, mS(i - b, a, b, c) + 1);
    if (i - c >= 0)
        ans = max(ans, mS(i - c, a, b, c) + 1);

    return dp[i] = ans;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        for (int i = 0; i < dp.size(); i++)
            dp[i] = INT_MIN;

        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int mSolve = mS(n, a, b, c);
        cout << mSolve;
    }
}

/*
Input
5 5 3 2

O/p
2

*/