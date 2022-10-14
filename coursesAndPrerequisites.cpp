// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

#include <bits/stdc++.h>

using namespace std;

bool cycleCheck(vector<vector<int>> &adj, vector<bool> &vis, int u)
{
    if (vis[u])
        return true;
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (cycleCheck(adj, vis, v))
        {
            vis[u] = false;
            return true;
        }
    }
    vis[u] = false;
    return false;
}

bool canFinish(int numCourses, vector<pair<int, int>> &prereq)
{
    vector<vector<int>> adj(numCourses);
    for (auto req : prereq)
    {
        adj[req.first].push_back(req.second);
    }

    vector<bool> vis(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
    {
        if (!vis[i])
        {
            if (cycleCheck(adj, vis, i))
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> prereq(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> prereq[i].first >> prereq[i].second;
    }
    cout << boolalpha << "All courses can be finished : " << canFinish(n, prereq) << endl;
}