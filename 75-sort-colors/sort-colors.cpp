class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        bool isSorted;
        for (int i = 0; i < n-1; i++) {
            isSorted = false;
            for (int j = 0; j < n-i-1; j++) {
                if (nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    isSorted  = true;
                }
            }
            if (isSorted == false) {
                break;
            }
        }
    }
};