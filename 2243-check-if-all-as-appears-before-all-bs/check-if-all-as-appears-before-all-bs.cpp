class Solution {
public:
    bool checkString(string s) {
        for(int i=1;i<s.size();i++){
            int ch1=s[i-1];
            int ch2=s[i];

            if(ch1>ch2) return false;
        }

        return true;
    }
};