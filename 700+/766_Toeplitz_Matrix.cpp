/* 766. Toeplitz Matrix
 * Check each diagonal from top-left to bottom-right to see if
 * it matches the requirement
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0, j = n-1; !(i == m-1 && j == 0);){
            int i0 = i, j0 = j, val = matrix[i][j];
            while(i0 < m && j0 < n){
                if(matrix[i0][j0] != val) return false;
                i0++;
                j0++;
            }
            if(j > 0){
                j--;
            }else{
                i++;
            }
        }
        return true;
    }
};