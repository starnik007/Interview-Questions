//link for the question: https://codeforces.com/problemset/problem/1245/d 
//implementaion of kruskal algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = (ll)(2001);
ll parent[N];
ll Size[N];
//disjoint set union
void make(ll v)
{
	parent[v] = v;
	Size[v] = 1;
}
ll find(ll v)
{
	if (v == parent[v])
	{
		return v;
	}
	return (parent[v] = find(parent[v]));
}
void Union(ll a, ll b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		if (Size[a] < Size[b])
		{
			swap(a, b);
		}
		parent[b] = a;
		Size[a] += Size[b];
	}
}
int main()
{
	ll n;
	cin >> n;
	vector<pair<ll, ll>> cities(n + 1);
	for (ll i = 0; i <= n; i++)
	{
		make(i);
	}
	for (ll i = 1; i <= n; i++)
	{
		cin >> cities[i].first >> cities[i].second;
	}
	vector<ll> c(n + 1); //cost of power grid
	for (ll i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	vector<ll> k(n + 1);
	for (ll i = 1; i <= n; i++)
	{
		cin >> k[i];
	}
	vector<pair<ll, pair<ll, ll>>> ans;
	for (ll i = 1; i <= n; i++)
	{
		ans.push_back({c[i], {0, i}});
	}
	//store the weight of the graph i.e. cost to connect cities
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i + 1; j <= n; j++)
		{
			ll dis = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
			ll cost = dis * (k[i] + k[j]);
			ans.push_back({cost, {i, j}});
		}
	}
	// sorting according to the weights
	sort(ans.begin(), ans.end());
	vector<ll> ps; // stores the power stations
	vector<pair<ll, ll>> con; // stores the connections between cities
	ll cst = 0;
	//applying kruskal algorithm
	for (auto i : ans)
	{
		ll wt = i.first;
		ll u = i.second.first;
		ll v = i.second.second;
		if (find(u) == find(v))
		{
			continue;
		}
		cst += wt;
		Union(u, v);
		if (u == 0 || v == 0)
		{
			ps.push_back(max(u, v));
		}
		else
		{
			con.push_back({u, v});
		}
	}
	cout << cst << "\n";
	cout << ps.size() << "\n";
	for (auto i : ps)
	{
		cout << i << " ";
	}
	cout << "\n";
	cout << con.size() << "\n";
	for (auto i : con)
	{
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}