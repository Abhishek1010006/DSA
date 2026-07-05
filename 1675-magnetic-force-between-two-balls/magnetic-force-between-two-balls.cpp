class Solution {
public:
    bool isPossible(vector<int>& position, int m,int mid,int size){
        int PositionCount = 1;
        int lastPos=position[0];

        for(int i=0;i<size;i++){
            if(position[i]-lastPos >= mid){
                PositionCount++;
                if(PositionCount == m) return true;
                lastPos=position[i];
            }
        }    
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int s=0;
        long long int sum=0;
        int ans=-1;
        int size=position.size();
        sort(position.begin(), position.end());
        long long int e=position[size - 1] - position[0];


        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if( isPossible(position,m,mid,size) ){
                ans=mid;
                s=mid + 1;
            }

            else{
                e=mid -1;
            }
        }
        return ans;
    }
};