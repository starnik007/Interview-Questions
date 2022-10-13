class Solution {
public:
    void combSum(int i, int sum, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int target)
    {
        if(sum>target)
            return;
        if(i>=candidates.size())
        {
            if(sum == target)
                ans.push_back(ds);
            return;
        }
        sum+=candidates[i];
        ds.push_back(candidates[i]);
        combSum(i, sum, ds, ans, candidates, target);
        sum-=candidates[i];
        ds.pop_back();
        combSum(i+1, sum, ds, ans, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        combSum(0, 0, ds, ans, candidates, target);
        return ans;
    }
};
