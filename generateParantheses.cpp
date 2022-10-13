class Solution {
public:
    void generatePara(vector<string> &ans, string &s, int left, int right)
    {
        if(left == 0 && right == 0) 
        {
            ans.push_back(s);
            return;
        }
        if(left > 0)
        {
            s.push_back('(');
            left--;
            generatePara(ans, s, left, right);
            s.pop_back();
            left++;
        }
        if(right > left )
        {
            s.push_back(')');
            right--;
            generatePara(ans, s, left, right);
            s.pop_back();
            right++;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generatePara(ans, s, n, n);
        return ans;
    }
};
