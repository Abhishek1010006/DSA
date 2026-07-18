class Solution {
public:
    bool isAnagram(string s, string t) {
        int count1[26]={0};
        int count2[26]={0};
        for(char ch:s){
            count1[ch-'a']++;
        }
        for(char ch:t){
            count2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]) return false;
        }

        return true;
        
    }
};