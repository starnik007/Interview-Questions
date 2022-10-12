#include<bits/stdc++.h>
using namespace std;

int bfsCheck(vector<int> adj[],int node,vector<int> &color){
    queue<int>q;
    color[node]=1;
    q.push(node);
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(auto i:adj[n]){
            if(color[i]==-1){
                color[i]=1-color[n];
                q.push(i);
            }
            else if(color[i]==color[n])
                    return false;
        }
    }
    return true;
}

int dfsCheck(vector<int> adj[],int node,vector<int> &color){
    for(auto i:adj[node]){
        if(color[i]==-1){
            color[i]=1-color[node];
            if(!dfsCheck(adj,i,color))
                return false;
        }
        else if(color[i]==color[node])
                return false;
    }
    return true;
}

int checkBipartite(vector<int> adj[],int V){
    vector<int> color(V,-1);
    for (int i = 0; i < V; i++)
    {
        if(color[i]==-1)
            if(!dfsCheck(adj,i,color))
                return false;
    }
    return true;
}

void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main() {
    
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);

    if(checkBipartite(adj, 6)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
}
/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 
