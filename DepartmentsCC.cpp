//link for the question: https://www.codechef.com/problems/DPRTMNTSEASY?tab=statement
// implementation of breadth first search in cpp in cp
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
    ll n, m;
    cin >> n; 
    cin >> m;
    vector<ll> adj[n + 1]; // adjacency list
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<ll> parent(n + 1, 0); // storing the group of a node
    vector<bool> vis(n + 1, 0); // whether a node is visited
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    set<ll> s;
	// breadth first search
    while (!q.empty())
    {
      ll temp = q.front();
      q.pop();
      ll h = temp;
      for (auto i : adj[temp])
      {
        if (adj[i].size() > adj[temp].size())
        {
          h = i;
        }
        if (!vis[i])
        {
          vis[i] = 1;
          q.push(i);
        }
      }
      s.insert(h);
    }
    for (auto i : s)
    {
      parent[i] = i;
    }
    vector<bool> vis1(n + 1, 0);
    for (auto j : s)
    {
      queue<ll> q1;
      q1.push(j);
      vis[j] = 1;
      while (!q1.empty())
      {
        ll temp = q1.front();
        q1.pop();
        for (auto i : adj[temp])
        {
          if (!vis1[i])
          {
            vis[i] = 1;
            q.push(i);
            if (parent[i] != i)
            {
              parent[i] = j;
            }
          }
        }
      }
    }
    cout << s.size() << "\n";
    map<ll, ll> mpp;
    ll cnt = 1;
    for (auto i : s)
    {
      mpp[i] = cnt;
      cnt++;
    }
    for (ll i = 1; i < parent.size(); i++)
    {
      cout << mpp[parent[i]] << " "; 
    }
    cout << "\n";
    for (auto i : s)
    {
      cout << i << " "; // printing memebers of the group
    }
    cout << "\n";
  }
  return 0;
}