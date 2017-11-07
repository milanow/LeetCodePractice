/* 542. 01 Matrix
 * Each cell's distance to zero is related to:
 * 1. Is itself '0'
 * 2. min distance of 4 cells(up, down, left, right) + 1
 * Thus we need to check 4 directions dynamically
 * However we can only check 2 directions one time
 * To check 4 directions, we can iteratre from top-left corner (checking left and up)
 * and iterate from bottom-right corner (checking right and down);
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return vector<vector<int>>();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0){
                    int tmp = min(i > 0? dp[i-1][j]: INT_MAX, j > 0? dp[i][j-1]: INT_MAX);
                    if(tmp != INT_MAX){
                        dp[i][j] = tmp + 1;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] != 0){
                    int tmp = min(i < m-1? dp[i+1][j]: INT_MAX, j < n-1? dp[i][j+1]: INT_MAX);
                    if(tmp != INT_MAX){
                        dp[i][j] = min(dp[i][j], tmp+1);
                    }
                }
            }
        }
        return dp;
    }
};