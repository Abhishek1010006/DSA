class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int s=0;
         int row=matrix.size();
         int col=matrix[0].size();

         int LastCol=col-1;
         int FirstRow=0;

         while(LastCol>=0 && FirstRow<row){
            int element=matrix[FirstRow][LastCol];

            if(element == target) return 1;

            if(element < target) FirstRow++;

            else LastCol--;
         }

         return 0;
    }
};