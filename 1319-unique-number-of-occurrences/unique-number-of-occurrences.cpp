class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size=arr.size();
        int count=1;
        vector<int> co;

        sort(arr.begin(),arr.end());

        for(int i=1;i<size;i++){
                if(arr[i]==arr[i-1]){
                    count++;
                }

                else{
                    co.push_back(count);
                    count=1;
                }
        }
        co.push_back(count);


        for(int k=0;k<co.size();k++){
            for(int p=k+1;p<co.size();p++){
                if(co[k]==co[p]){
                    return false;
                }
                }
            }

            
        return true;
    }
};


