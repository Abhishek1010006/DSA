class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
            }
        }

        // This is done because array sorted hai last ke largest numbers hi aage aayenge 
        if(nums[nums.size()-1]>nums[0]) count++;

        return count<=1;
    }
};