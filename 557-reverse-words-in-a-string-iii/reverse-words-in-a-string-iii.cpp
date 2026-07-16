class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=s.size();
        string ans;
        string word;
        while(i<j){
            if(s[i]!=' '){
                word+=s[i++];
            }

            else{
                i++;
                reverse(word.begin(),word.end());
                ans+=' '+word;
                word.clear();
                continue;
            }
        }
        reverse(word.begin(),word.end());
        ans+=' '+word;
        return (ans.substr(1));
    }
};