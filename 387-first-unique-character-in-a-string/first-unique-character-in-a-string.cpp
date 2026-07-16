class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(char ch: s){
            int number=0;
            if(ch>='a' && ch<='z'){
                number=ch - 'a';
            }

            if(ch>='A' && ch<='Z'){
                number=ch-'A';
            }

            arr[number]++;
        }

        int index=0;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a']==1){
                return i;
            }
        }

        return -1;

    }
};