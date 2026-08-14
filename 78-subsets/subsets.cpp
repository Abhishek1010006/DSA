class Solution {
public:
    void SubSets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets){
        if(i==nums.size()) {
            allSubsets.push_back(ans);
            return;
        }
        // Include
        ans.push_back(nums[i]);
        SubSets(nums, ans, i+1,allSubsets); 
        
        ans.pop_back();
        
        // Exclude
        SubSets(nums, ans, i+1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        
        SubSets(nums,ans,0,allSubsets);

        return allSubsets;
    }
};