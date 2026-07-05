class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        long long int mid= s + (x-s)/2;
        long long int ans= -1;
        long long int e =x;

        while(e>=s){
            long long int square= mid * mid;

            if(square ==x){
                ans = mid;
                return mid;
            }

            else if(square > x){
                e=mid-1;            
            }
            
            else{
                s= mid +1;
                ans = mid;    
            }

            mid= s + (e-s)/2;
        }
        return ans;
    }
};