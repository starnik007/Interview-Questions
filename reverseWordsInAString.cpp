class Solution {
public:
    string reverseWords(string s) {
        int n = s.length()-1;
        int x =s.length();
        while(n>=0){
            if(s[n] == ' '){
                n--;
                continue;
            }
            string temp = "";
            while(n>=0 && s[n] != ' ' ){
                temp += s[n--];
            }
            reverse(temp.begin(),temp.end());
            s += temp;
            s += ' ';
        } 
        s.pop_back();
        return s.substr(x);
    }
};
