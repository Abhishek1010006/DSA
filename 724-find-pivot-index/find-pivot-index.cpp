class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightsum=0;
        int leftsum=0;
        for(int i=0;i<size(nums);i++){
            rightsum=rightsum+nums[i];
        }

        for(int j=0;j<size(nums);j++){
            rightsum-= nums[j];

            if(leftsum==rightsum){
                return j;
            }
            leftsum+= nums[j];
        }
        return -1;
    }
};