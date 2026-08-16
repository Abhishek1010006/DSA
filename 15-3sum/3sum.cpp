class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> triplet;

        sort(nums.begin(), nums.end());
        int i=0 , j=1, k=nums.size()-1;

        for(int i=0; i<nums.size();i++){
            j=i+1, k=nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            while(j < k){
                long long sum=(long long) nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    triplet={nums[i],nums[j],nums[k]};
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])
                        j++;

                    while(j < k && nums[k] == nums[k+1])
                        k--;
                    ans.push_back(triplet);
                }

                else if(sum>0){
                    k--;
                }

                else{
                    j++;
                }
            }
        }

        return ans;
    }
};