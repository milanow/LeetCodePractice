/* 807. Max Increase to Keep City Skyline
 * We need two iterations to collect and calculate
 * The first iteration is to collect information of the skyline, 
 * Using two arrays to record the top/bottom and left/right skylines
 * indvisually. 
 * The second iteration, we need to calculate how many number we could add
 * to current grid[i][j] to keep the two skylines
 * Simply by comparing the min of two skyline with that cell and added the
 * difference to sum. (Note min(skylines) must be bigger than grid[i][j])
 */

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid.size();
        if(!n) return 0;
        
        // original top/bottom skyline
        vector<int> tp(n, 0);
        // original left/right skyline
        vector<int> lr(m, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                lr[i] = max(lr[i], grid[i][j]);
                tp[j] = max(tp[j], grid[i][j]);
            }
        }
        
        int sum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum += (min(lr[i], tp[j]) - grid[i][j]);
            }
        }
        return sum;
    }
};