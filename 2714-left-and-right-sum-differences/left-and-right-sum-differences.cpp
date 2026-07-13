class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftsum=0;
        int rightsum=0;
        vector<int> lsum;
        vector<int> rsum;
        vector<int> result;
        int ans;

        for(int i=0;i<size(nums);i++){
            rightsum+=nums[i];
        }

        for(int j=0;j<size(nums);j++){
            lsum.push_back(leftsum);
            rightsum-=nums[j];
            leftsum+=nums[j];
            rsum.push_back(rightsum);
        }

        for(int k=0;k<size(rsum);k++){
            ans=lsum[k]-rsum[k];
            if(ans<0){
                ans=-ans;
                result.push_back(ans);
            }

            else{
                result.push_back(ans);
            }
        }

        return result;
    }
};