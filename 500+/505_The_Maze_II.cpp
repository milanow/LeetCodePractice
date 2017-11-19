/* 505. The Maze II
 * BFS solution, put every reachable cell and updating the min steps needed
 * When finished, check the destination cell
 */

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if(!m) return -1;
        int n = maze[0].size();
        if(!n) return -1;
        
        vector<vector<int>> mp(m, vector<int>(n, -1));
        const vector<vector<int>> dirs{{0,-1}, {0,1}, {-1,0}, {1,0}};
        //BFS
        mp[start[0]][start[1]] = 0;
        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int cost = mp[x][y];
            
            for(int k = 0; k < 4; k++){
                int i = x;
                int j = y;
                int step = 0;
                int dirx = dirs[k][0];
                int diry = dirs[k][1];
                while(i + dirx >= 0 && i + dirx < m && j + diry >= 0 && j + diry < n && maze[i+dirx][j+diry] == 0){
                    ++step;
                    i += dirx;
                    j += diry;
                }
                
                if(mp[i][j] == -1 || mp[i][j] > cost + step){
                    mp[i][j] = cost + step;
                    q.emplace(i, j);
                }
            }
        }
        return mp[destination[0]][destination[1]];
    }
    
};