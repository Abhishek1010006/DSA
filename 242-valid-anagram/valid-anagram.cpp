class Solution {
public:
    bool isAnagram(string s, string t) {
        int count1[26]={0};
        int count2[26]={0};
        for(int i=0;i<s.size();i++){
            int num=s[i]-'a';
            count1[num]++;
        }
        for(int i=0;i<t.size();i++){
            int num=t[i]-'a';
            count2[num]++;
        }
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]) return false;
        }

        return true;
        
    }
};