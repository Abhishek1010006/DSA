class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
        int StudentCount=1;
        int PageSum = 0;
        for(int i=0; i<nums.size();i++){

            if(nums[i]>mid) return false;

            if(PageSum + nums[i] <= mid) 
                PageSum+=nums[i];

            else{
                StudentCount++;
                PageSum = nums[i];
                if(StudentCount > k) return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int sum=0;
        int ans =-1;
        
        for(int i=0; i<nums.size() ;i++){
            sum+=nums[i];
        }

        int e=sum;

        int mid= s + (e-s)/2;

        while(e>=s){
            if(isPossible(nums,k,mid)){
                ans = mid;
                e=mid - 1;
            }

            else{
                s=mid + 1;
            }
            mid= s + (e-s)/2;
        }
        return ans;
    }
};