class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int count=0;
    int size=nums.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count==1){
            return nums[i];
        }
        count=0;
    }
    return 0;
    }
};