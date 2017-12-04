/* 490. The Maze
 * A typical dfs solution, no need to check visited cell because the problem is to find out
 * if it could have a solution
 * note: if(!visited[rowball][colball]) represents if the ball has rolled and the new position
 *     is not visited. Adding (rowdir == 0 && coldir == 0) because the starting position doesn't move
 *     but it needs to roll
 */

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visitmap(m, vector<bool>(n, false));
        return dfs(maze, visitmap, start[0], start[1], destination[0], destination[1], 0, 0);
    }
    
    bool dfs(vector<vector<int>>& mz, vector<vector<bool>>& visited, int rowball, int colball, int rowdest, int coldest, int rowdir, int coldir){
        if(rowball == rowdest && colball == coldest) return true;
        visited[rowball][colball] = true;
        
        if(rowdir != 0 || coldir != 0){
            while(rowball + rowdir >= 0 && colball + coldir >= 0 && rowball + rowdir < mz.size() && colball + coldir < mz[0].size() && mz[rowball + rowdir][colball + coldir] == 0){
                rowball += rowdir;
                colball += coldir;
            }
        }
        
        if(!visited[rowball][colball] || rowdir == 0 && coldir == 0){
            if(rowdir == 0){
                if(dfs(mz, visited, rowball, colball, rowdest, coldest, 1, 0) || dfs(mz, visited, rowball, colball, rowdest, coldest, -1, 0))
                    return true;
            }
            if(coldir == 0){
                if(dfs(mz, visited, rowball, colball, rowdest, coldest, 0, 1) || dfs(mz, visited, rowball, colball, rowdest, coldest, 0, -1))
                    return true;
            }
        }
        return false;
    }
};