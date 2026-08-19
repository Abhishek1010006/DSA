class Solution {
public:
    void solve(string &digits,int idx,string &current, vector<string> map,vector<string> &ans){
        if(idx==digits.length()){
            ans.push_back(current);
            return;
        }

        int dig= digits[idx] - '0';
        string str=map[dig];

        for(int i=0;i<str.length();i++){
            current.push_back(str[i]);

            solve(digits,idx+1,current,map,ans);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
       vector<string> map= {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

       string current;
       vector<string> ans;

       solve(digits,0,current,map, ans);

       return ans;
       
    }
};