class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26]={0};
        for(char ch:s){
            int number=0;
            arr[ch-'a']++;

            if(arr[ch-'a']==2) return ch;
        }

        return -1;
    }
};