class Solution {
public:
    void GetTerms(vector<int> &nums,int idx, vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;
        }
        unordered_set<int> used;
        for(int i=idx;i<nums.size();i++){
            //Removing Duplicates
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            
            // Base Case
            swap(nums[idx],nums[i]); //idx place => oth element choice
            GetTerms(nums,idx+1,ans);

            // Backtracking 
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        GetTerms(nums,0,ans);

        return ans;
    }
};