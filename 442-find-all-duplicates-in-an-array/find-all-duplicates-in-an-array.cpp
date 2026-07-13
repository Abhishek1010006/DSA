class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> co;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]){
                co.push_back(nums[i]);
                nums[i]=-11202;
            }
        }
        return co;
    }
};