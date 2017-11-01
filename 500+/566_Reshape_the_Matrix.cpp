/* 566. Reshape the Matrix
 * the matrix is valid only if row*col = newrow*newcol to ensure container size is the same
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        if(!row) return nums;
        int col = nums[0].size();
        if(!col) return nums;
        
        if(row*col != r*c) return nums;
        vector<vector<int>> newnums(r, vector<int>(c, 0));
        int x = 0, y = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(y == c){
                    y = 0;
                    x++;
                }
                newnums[x][y++] = nums[i][j];
            }
        }
        return newnums;
        
    }
};