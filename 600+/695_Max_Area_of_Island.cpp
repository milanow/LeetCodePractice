/* 695. Max Area of Island
 * Check each island by dfs marking all visited cells
 * and keep updating the max area of each found islands
 */

class Solution {
    const int dirs[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j, m, n);
                    mx = max(mx, area);
                }
            }
        }
        
        return mx;
    }
        
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n){
        grid[row][col] *= -1;
        int area = 1;
        for(int i = 0; i < 4; i++){
            int newr = row + dirs[i][0];
            int newc = col + dirs[i][1];

            if(newr < 0 || newc < 0 || newr >= m || newc >= n || grid[newr][newc] <= 0) continue;
            area += dfs(grid, newr, newc, m, n);
        }
        return area;
    }
};