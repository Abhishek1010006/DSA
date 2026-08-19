class Solution {
public:
    void permutation(vector<int> &nums, int idx, vector<vector<int>> &ans){
        int n= nums.size();
        if(idx == n){
            ans.push_back(nums);
        }

        unordered_set<int> used;

        for(int i=idx;i<n;i++){
            if(used.count(nums[i])) continue;
                used.insert(nums[i]);

            swap(nums[i],nums[idx]);
            permutation(nums, idx+1, ans);

            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permutation(nums, 0, ans);

        return ans;
    }
};