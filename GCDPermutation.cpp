// link for the question: https://www.codechef.com/problems/PERMGCD
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
const ll N = 100000;
const ll M = (ll)1000000007;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, x;
    cin >> n >> x;
    ll temp = (n * (n + 1)) / 2;
    if (x < n || x > temp)
    {
      cout << "-1\n";
    }
    else if (x == n)
    {
      for (ll i = 0; i < n; i++)
      {
        cout << i + 1 << " ";
      }
      cout << "\n";
    }
    else
    {
      cout << x - n + 1 << " ";
      for (int i = 1; i < n; i++)
      {
        if (i >= x - n + 1)
        {
          cout << i + 1 << " ";
        }
        else
        {
          cout << i << " ";
        }
      }
      cout << "\n";
    }
  }
  return 0;
}