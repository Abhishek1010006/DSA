class Solution {
public:
    int compress(vector<char>& chars) {
        char ch;
        int count=0;
        int index=0;
        for(int i=0;i<chars.size();i++){
            char ch=chars[i];
            int count=0;
            while(i<chars.size() && ch==chars[i]){
                i++;
                count++;
            }

            if(count==1) chars[index++]=ch;

            else{
                chars[index++]=ch;
                string num=to_string(count);
                for(char c :num){
                    chars[index++]=c;
                }
            }
            i--;
        }

        // chars.resize(index);
        return index;
    }
};