/* 407. Trapping Rain Water II
 * Couldn't figure it out myself, so this is a solution coming from Leetcode forum:)
 * The core idea of this solution is to imagine the surrounding unit, which means units
 * whose i = 0 or m-1, j = 0 or n-1, as "bar". And water may flow out through the lowest
 * bar. The solution is to find out the lowest bar of each possible surrounded area and 
 * make the area as small as possible. That is to say "pushing the bar inside". 
 * e.g.
 * 2 2 2 2 2
 * 2 0 0 0 2
 * 2 0 0 0 1
 * 2 2 2 2 2
 * the lowest bar as the beginning is 1, then we "push" the '1' cell inside. it becomes
 * 2 2 2 2 2
 * 2 0 0 0 2
 * 2 0 0 1
 * 2 2 2 2 2
 * now the trapped water should be added 1 - 0 = 1, and so on.
 * Each iteration we pushing the lowest bar/cell inside to collect water
 */

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(!m) return 0;
        int n = heightMap[0].size();
        if(!n) return 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    pq.push(make_pair(heightMap[i][j], i*n+j));
                    visited[i][j] = true;
                }
            }
        }

        int ans = 0;
        const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int h = p.first, x = p.second/n, y = p.second%n;
            
            for(int i = 0; i < 4; i++){
                int newx = x + dirs[i][0], newy = y + dirs[i][1];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n || visited[newx][newy]) continue;
                visited[newx][newy] = true;
                ans += max(0, h - heightMap[newx][newy]);
                pq.push(make_pair(max(heightMap[newx][newy], h), newx*n + newy));
            }
        }
        return ans;
    }
};