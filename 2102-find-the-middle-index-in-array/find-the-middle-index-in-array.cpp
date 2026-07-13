class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int rightsum=0;
        int leftsum=0;

        for(int i=0;i<size(nums);i++){
            rightsum+=nums[i];
        }

        for(int j=0;j<size(nums);j++){
            rightsum-=nums[j];
            if(rightsum==leftsum){
                return j;
            }

            leftsum+=nums[j];
        }

        return -1;
    }
};