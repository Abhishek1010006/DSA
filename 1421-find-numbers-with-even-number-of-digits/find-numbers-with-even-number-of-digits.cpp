class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int EvenDigit=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=0){
                nums[i]=nums[i]/10;
                count++;
            }
            if(count%2==0) EvenDigit++;
            count=0;
        }
        return EvenDigit;
    }
};