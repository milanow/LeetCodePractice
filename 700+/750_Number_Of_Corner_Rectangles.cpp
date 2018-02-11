/* 750. Number Of Corner Rectangles
 * i0 & j0 is the left-top corner of a rectangle, i & j is the right-bottom corner
 * of a rectangle. 
 */

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i0 = 0; i0 < m; i0++){
            for(int j0 = 0; j0 < n; j0++){
                for(int i = i0 + 1; i < m && grid[i0][j0]; i++){
                    for(int j = j0 + 1; j < n && grid[i][j0]; j++){
                        cnt += grid[i][j] && grid[i0][j];
                    }
                }
            }
        }
        return cnt;
    }
};