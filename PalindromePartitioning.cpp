#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int t[501][501]; 
    bool isPalin(string &s,int i,int j) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            else i++,j--;
        }
        return true;
    }

    int solve(string &s,int i,int j) {
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(isPalin(s,i,j)) return 0; 
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++) {
            int temp=solve(s,i,k)+solve(s,k+1,j)+1;
            ans=min(ans,temp);
        }
        return t[i][j]=ans;
    }

    int palindromicPartition(string &str) {
        memset(t,-1,sizeof(t));
        return solve(str,0,str.length()-1);
    }

};

int main(){
    string str;
    cin>>str;
    Solution ob;
    cout<<ob.palindromicPartition(str)<<"\n";
    return 0;
}
