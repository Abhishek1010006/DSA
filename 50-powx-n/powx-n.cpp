// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N=n;
//         long double ans=1;
        
//         if(N<0){
//             N=(-1)*N;
//             X=1/X;
//         }

//         while(N>0){

//         }
//         return ans;
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
       double ans= pow(x,n);
       return ans;
    }
};