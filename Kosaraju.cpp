#include <bits/stdc++.h>
using namespace std;

void dfs(int node,stack<int> &st,vector<int> &vis, vector<int> adj[])
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			dfs(it,st,vis,adj);
		}
	}
	st.push(node);
}

void revDfs(int node,vector<int> &vis, vector<int> adj[])
{
	cout<<node<<" ";
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			revDfs(it,vis,adj);
		}
	}
}

int main()
{
	int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}

	// part 1 (Topological Sort)
	stack<int>st;
	vector<int>vis(n,0);
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,st,vis,adj);
		}
	}

	// Part 2(Tranpose graph)
	vector<int>transposegraph[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
		for(auto it:adj[i])
		{
			transposegraph[it].push_back(i);
		}
	}

	// Reverse DFS
	while(!st.empty())
	{
		int node= st.top();
		st.pop();
		if(!vis[node])
		{
			cout << "SCC: "; 
	        revDfs(node, vis, transposegraph); 
	        cout << endl; 
		}
	}

	return 0;
}