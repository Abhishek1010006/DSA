class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x;
        bool ans;
        for(int i=0;i<=30;i++){
            x=pow(2,i);
            if(n==x){
                ans= true;
            break;
            }
            else{
                ans= false;
            }
        }   
        return ans;
    }
};