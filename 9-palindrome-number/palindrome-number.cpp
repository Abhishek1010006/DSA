class Solution {
public:
    bool isPalindrome(int x) {
        long ans=0;
        bool a;
        int y=x;

        if(x<0){
            return false;
        }
        while(x !=0){
            long digit=x%10;
            ans=(ans*10)+digit;
            x=x/10;
        }

        if(y==ans){
                a=true;
        }

        else{
                a=false;
            }
        return a;
    }
};