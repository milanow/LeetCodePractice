/* 499. The Maze III
 * Other than Maze I, this problem focuses on finding the most efficient way to reach the hole
 * Also if there are mutiple min-step way, output the lexicographically smallest one.
 * TO find out the min step, we need to record the steps cost of previous dfs process.
 * Only if new dfs process has less step, it will be allowed to continue
 * 
 * This solution use orignal maze as a "visited map", if the cell is unvisited (equal 0)
 * or the cost is smaller (less than mz[x][y] - 2), it allow new dfs process to continue
 * 2 represents encoding, since 0 && 1 has been used.
 * in each dfs process, we pass down the direction and current ball location and rolling 
 * along the direction. When hitting a wall of finding the hole, we stop the rolling process
 */

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        return roll(maze, ball[0], ball[1], hole[0], hole[1], 0, 0, 0, "", pair<string, int>() = make_pair("impossible", INT_MAX));
    }
    
    string roll(vector<vector<int>>& mz, int rowball, int colball, int rowhole, int colhole, int rowdir, int coldir, int steps, const string& path, pair<string, int>& res){
        if(steps < res.second){
            if(rowdir != 0 || coldir != 0){
                // roll first
                while(rowball + rowdir >= 0 && colball + coldir >= 0 && rowball + rowdir < mz.size() && colball + coldir < mz[0].size() && mz[rowball + rowdir][colball + coldir] != 1){
                    steps++;
                    rowball += rowdir;
                    colball += coldir;
                    if(rowball == rowhole && colball == colhole && steps < res.second) res = make_pair(path, steps);
                }
            }
            
            // use original maze as a visited_map, only when maze's cell is not visited or having smaller steps can roll
            if(mz[rowball][colball] == 0 || steps + 2 < mz[rowball][colball]){
                mz[rowball][colball] = steps + 2;
                // rolling from the order: 'd', 'l', 'r', 'u', such that the final result would be lexicographically min
                if(rowdir == 0) roll(mz, rowball, colball, rowhole, colhole, 1, 0, steps, path + "d", res);
                if(coldir == 0) roll(mz, rowball, colball, rowhole, colhole, 0, -1, steps, path + "l", res);
                if(coldir == 0) roll(mz, rowball, colball, rowhole, colhole, 0, 1, steps, path + "r", res);
                if(rowdir == 0) roll(mz, rowball, colball, rowhole, colhole, -1, 0, steps, path + "u", res);
            }
        }
        
        return res.first;
    }
};