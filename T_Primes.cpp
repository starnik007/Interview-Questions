/*https://codeforces.com/contest/230/problem/B*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int isprime(double n)
{
    if (ceil(n) != floor(n))
        return 0;
    int cnt = 0;
    if (n == 1)
        return 0;
    int n1 = (int)round(n);
    for (int i = 2; i * i <= (n1); i++)
        if (n1 % i == 0)
            cnt++;
    if (cnt == 0 || n1 == 2)
        return 1;
    return 0;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        REP(i, 0, n - 1)
        cin >> v[i];
        REP(i, 0, n - 1)
        {
            if (isprime(sqrt(v[i])))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
