class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int a[128]={0};
        int b[s.size()];
        for(int i=0;i<s.size();i++){
            b[i]=0;
        }
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size() && a[s[j]-' ']==0;j++){
                a[s[j]-' ']++;
                count++;
            }
            b[i]=count;
            count=0;
            for(int i=0;i<128;i++){
                a[i]=0;
            }
        }
        int max=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(b[i]>max){
                max=b[i];
            }
        }
        return max;
    }
};
