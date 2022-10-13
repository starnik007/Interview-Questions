/*https : // codeforces.com/contest/219/problem/A*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        map<char, int> m;
        int flag = 0;
        REP(i, 0, s.size() - 1)
        {
            m[s[i]]++;
        }
        for (auto mtr : m)
        {
            if (mtr.second % k != 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            cout << "-1" << endl;
        else
        {
            string s1 = "";
            for (auto mtr : m)
            {
                for (int i = 1; i <= mtr.second / k; i++)
                    s1 = s1 + mtr.first;
            }
            for (int i = 1; i <= k; i++)
                cout << s1;
        }
    }
}