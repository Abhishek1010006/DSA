class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int sum=0;
        int carry=0;
        int digit=0;
        int i=num.size()-1;
        int j=0;
        while(i>=0 && k>0){
            digit=k%10;
            k/=10;
            sum=num[i]+digit+carry;
            carry=sum/10;
            ans.push_back(sum%10);
            i--;
        }

        while(i>=0){
            sum=num[i]+carry;
            carry=sum/10;
            ans.push_back(sum%10);
            carry=sum/10;
            i--;
        }

        while(k>0){
            digit=k%10;
            k/=10;
            sum=digit+carry;
            ans.push_back(sum%10);
            carry=sum/10;
        }

        if(carry!=0) ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};