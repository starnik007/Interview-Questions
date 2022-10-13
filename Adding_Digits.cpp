/*https://codeforces.com/problemset/problem/260/A*/

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
        ll a, b, n;
        cin >> a >> b >> n;

        int i = 0;
        a *= 10;
        int flag = 0;
        while (i <= 9)
        {
            a += i;
            if (a % b == 0)
            {
                flag = 1;
                break;
            }
            a -= i;
            i++;
        }
        if (flag == 0)
            cout << "-1" << endl;
        else
        {
            string s = to_string(a);
            while (n - 1)
            {
                s += '0';
                n--;
            }
            cout << s << endl;
        }
    }

    return 0;
}