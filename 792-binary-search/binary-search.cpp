class Solution {
private:
    int Bsearch(vector<int>& numi,int tar,int st,int end){
            if(st<=end){
                int mid= st + (end-st)/2;
                if(numi[mid]==tar) return mid;
                if(numi[mid]>=tar) 
                    return Bsearch(numi,tar,st,mid-1);
                if(numi[mid]<=tar)
                    return Bsearch(numi,tar,mid+1,end);
            }

            return -1;
        }
public:
    int search(vector<int>& nums, int target) {
        return Bsearch(nums,target,0,nums.size()-1);
    }
};