class Solution {
public:
        
        int firstOccurance(vector<int> & nums, int target){
            int start=0;
            int end=nums.size() -1;
            int ans1 = -1;
            int mid= start + (end-start)/2;

            while(start<=end){
                if(nums[mid]== target){
                    ans1= mid;
                    end=mid - 1;
                }

                else if(nums[mid] > target){
                    end=mid-1;
                }

                else{
                    start=mid + 1;
                }

                mid= start + (end-start)/2;
            }
            return ans1;
        }

        int lastOccurance(vector<int> & nums, int target){
              int start=0;
              int end=nums.size() -1;
              int ans2=-1;
              int mid= start + (end-start)/2;

            while(start<=end){
                if(nums[mid]== target){
                    ans2= mid;
                    start=mid + 1;
                }

                else if(nums[mid] > target){
                    end=mid-1;
                }

                else{
                    start=mid + 1;
                }

                mid= start + (end-start)/2;
            }
            return ans2;
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            
            int first= firstOccurance(nums,target);
            int last= lastOccurance(nums,target);
            
            vector<int> answer;
            answer.push_back(first);
            answer.push_back(last);

            return answer;
          }
    };