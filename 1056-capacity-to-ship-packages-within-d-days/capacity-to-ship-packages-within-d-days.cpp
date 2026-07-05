class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int mid){
        int DayCount=1;
        int WeightSum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid) return false;

            if(weights[i] + WeightSum <= mid) WeightSum+=weights[i];

            else{
                DayCount++;
                WeightSum = weights[i];
                if(DayCount > days) return false;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int sum=0;
        
        for(int i=0;i<weights.size();i++) sum+=weights[i];

        int e=sum;
        int mid;
        int ans=-1;
        while(s<=e){
            mid = s + (e - s)/2;
            if (isPossible(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s= mid +1;
            }
        }
        return ans;
        
    }
};