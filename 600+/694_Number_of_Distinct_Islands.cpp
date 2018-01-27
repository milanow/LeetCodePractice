/* 694. Number of Distinct Islands
 * This problem can be divied two parts
 * 1. counting islands
 * 2. find repeating islands
 * for the first part, we can count the island by dfs marking all islands' cell
 * for second part, the key is how to represent a unique island, the answer is recording
 * every coord difference of cell and island's left-top cell. Then a set to eliminate
 * repeated islands.
 */

class Solution {
    const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<vector<int>>> islands;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<vector<int>> newisland;
                    dfs(grid, newisland, i, j, i, j, m, n);
                    islands.insert(newisland);
                }
            }
        }
        return islands.size();
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& island, int x0, int y0, int x, int y, int m, int n){
        grid[x][y] *= -1;
        island.push_back({x-x0, y-y0});
        for(int i = 0; i < 4; i++){
            int newx = x+dirs[i][0];
            int newy = y+dirs[i][1];
            if(newx < 0 || newy < 0 || newx >= m || newy >= n || grid[newx][newy] <= 0) continue;
            dfs(grid, island, x0, y0, newx, newy, m, n);
        }
    }
};