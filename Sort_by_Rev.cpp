/*https://codeforces.com/contest/451/problem/B*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define endl "\n"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        REP(i, 0, n - 1)
        cin >> v[i];
        if (n == 1)
            cout << "yes\n1 1";
        else
        {
            int f1 = 0, f2 = 0;
            vector<ll> v1 = v;
            sort(v1.begin(), v1.end());
            for (int i = 0; i < n; i++)
            {
                if (v[i] != v1[i])
                {
                    f1 = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i] != v1[i])
                {
                    f2 = i;
                    break;
                }
            }
            reverse(v.begin() + f1, v.begin() + f2 + 1);

            int flag = 0;
            REP(i, 0, n - 1)
            {
                if (v[i] != v1[i])
                {
                    flag = -1;
                    break;
                }
            }
            if (flag == -1)
                cout << "no" << endl;
            else
            {
                cout << "yes" << endl;
                cout << f1 + 1 << " " << f2 + 1 << endl;
            }
        }
    }

    return 0;
}