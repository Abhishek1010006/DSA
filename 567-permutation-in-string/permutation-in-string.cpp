class Solution {
private: 
    int compare(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }

        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};

        for(int i=0;i<s1.size();i++){
            int num=s1[i] - 'a';
            count1[num]++;
        }

        for(int i=0;i<s2.size();i++){
            int count2[26]={0};
            int j=0;
            while(i+j<s2.size() && j<s1.size()){
                int num=s2[i+j]-'a';
                count2[num]++;
                j++;
            }

            if(compare(count1,count2)) return true;
        }

        return false;
    }
};