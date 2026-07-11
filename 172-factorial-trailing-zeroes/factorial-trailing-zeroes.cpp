class Solution {
public:
    int trailingZeroes(int n) {
        int numzero=0;

        while(n>=5){
            n=n/5;
            numzero=numzero + n;
        }    

        return numzero;     
    }
};