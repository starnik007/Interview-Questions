vector<vector<int>> dp;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        dp.assign(matrix.size()+1, vector<int> (matrix[0].size()+1,0));
        for(int i = 1; i<=matrix.size(); i++){
            for(int j = 1; j<=matrix[0].size(); j++){
                if(matrix[i-1][j-1] == '0')
                    dp[i][j] = 0;
                else 
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]}) + 1; 
            }
        }
        int ans = INT_MIN;
        for(auto v : dp){
            for(auto i : v){
                ans = max(ans,i);
            }
        }
        return ans*ans;
    }
};
