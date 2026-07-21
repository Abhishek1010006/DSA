class Solution {
public:
    int countPrimes(int n) {
        vector<bool> Prime(n+1,1);

        Prime[0]=Prime[1]=false;
        int count=0;

        for(int i=2;i<n;i++){
            if(Prime[i]==1){
                count++;
                for(int j=2*i;j<n;j+=i){
                    Prime[j]=0;
                }
            }
        }

        return count;
    }
};