#include<bits/stdc++.h>

using namespace std;

int minimumTime(vector<vector<int>> &fruits){
    int n = fruits.size(), m = fruits[0].size();
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(fruits[i][j] == 2) q.push({{i, j}, 0});
        }
    }
    
    // bfs
    int maxResult = 0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        maxResult = max(maxResult, curr.second);
        int curri = curr.first.first, currj = curr.first.second;
        if(curri - 1 >= 0 && fruits[curri-1][currj] == 1){
            q.push({{curri-1, currj}, curr.second+1});
            fruits[curri-1][currj] = 2;
        }
        if(curri + 1 < n && fruits[curri+1][currj] == 1){
            q.push({{curri+1, currj}, curr.second+1});
            fruits[curri+1][currj] = 2;
        }
        if(currj - 1 >= 0 && fruits[curri][currj-1] == 1){
            q.push({{curri, currj-1}, curr.second+1});
            fruits[curri][currj-1] = 2;
        }
        if(currj + 1 < m && fruits[curri][currj+1] == 1){
            q.push({{curri, currj+1}, curr.second+1});
            fruits[curri][currj+1] = 2;
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(fruits[i][j] == 1){
                return -1;
            }
        }
    }
    return maxResult;
}