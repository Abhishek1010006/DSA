class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();

        int total=row*col;

        int rigth=col-1;
        int bottom=row-1;
        int left=0;
        int top=0;

        int count=0;

        while(total>count){
            // printing left rigth
            for(int i=left;total>count && i<=rigth;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;

            // printing top to bottom
            for(int i=top; total>count && i<=bottom; i++){
                ans.push_back(matrix[i][rigth]);
                count++;
            }
            rigth--;

            // printing rigth to left
            for(int i= rigth;total>count && i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            // printing bottom to top
            for(int i=bottom ;total>count && i>=top;i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }

        return ans;
    }
};