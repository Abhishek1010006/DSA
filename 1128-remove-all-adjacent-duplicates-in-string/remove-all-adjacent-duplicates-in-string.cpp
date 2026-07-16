class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int i=0;
        for(char ch: s){
            if(!ans.empty() && ch==ans[ans.size()-1]){
                ans.pop_back();
            }

            else ans+=ch;
        }

        return ans;
    }
};