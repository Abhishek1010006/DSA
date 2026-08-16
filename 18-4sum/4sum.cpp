class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> fours;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int m = i + 1; m < nums.size(); m++) {
                if(m > i + 1 && nums[m] == nums[m - 1])
                    continue;

                int j = m + 1;
                int k = nums.size() - 1;

                while(j < k) {
                    long long sum = (long long)nums[i] + nums[m] + nums[j] + nums[k];

                    if(sum == target) {
                        fours = {nums[i], nums[m], nums[j], nums[k]};
                        ans.push_back(fours);

                        j++;
                        k--;

                        while(j < k && nums[j] == nums[j - 1])
                            j++;

                        while(j < k && nums[k] == nums[k + 1])
                            k--;
                    }
                    else if(sum > target) {
                        k--;
                    }
                    else {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};