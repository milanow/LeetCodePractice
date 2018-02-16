/* 764. Largest Plus Sign
 * This is still a dp problem
 * For each cell, we need to find out its up, down, left, right length of continuous '1'
 * However, with 3 dimensional grid, grid[N][N][4] might be using too much memory.
 * Instead, we record the min(up, down, right, left) of a cell instead of 4 spaces
 * In the second looping codes below, each cell is updated 4 times by comparing its
 * l, r, u, d.
 */

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, N));
        for(int i = 0; i < mines.size(); i++){
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0, k = N-1, l = 0, r = 0, u = 0, d = 0; j < N; j++, k--){
                grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0? 0: l+1));
                grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0? 0: r+1));
                grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0? 0: u+1));
                grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0? 0: d+1));
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                res = max(grid[i][j], res);
            }
        }
        return res;
    }
};