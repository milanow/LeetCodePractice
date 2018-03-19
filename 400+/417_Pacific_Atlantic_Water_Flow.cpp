/* 417. Pacific Atlantic Water Flow
 * A DFS solution. Starting from surrounding two oceans, who has different bit set,
 * Pacific: 1
 * Atlantic: 2
 * If a cell is marked visited as both 1 and 2. Then the cell can flow water to two oceans
 */

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return vector<pair<int, int>>();
        int n = matrix[0].size();
        if(!n) return vector<pair<int, int>>();
        
        vector<vector<int>> visit(m, vector<int>(n, 0));
        vector<pair<int, int>> res;
        for(int i = 0; i < m; i++){
            dfs(matrix, visit, i, 0, INT_MIN, 1, res);
            dfs(matrix, visit, i, n-1, INT_MIN, 2, res);
        }
        
        for(int j = 0; j < n; j++){
            dfs(matrix, visit, 0, j, INT_MIN, 1, res);
            dfs(matrix, visit, m-1, j, INT_MIN, 2, res);
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visit, int x, int y, int pre, int previsit, vector<pair<int, int>>& res){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] < pre || (visit[x][y] & previsit) == previsit) return;
       
        visit[x][y] |= previsit;
        if(visit[x][y] == 3) res.emplace_back(x, y);
        dfs(matrix, visit, x-1, y, matrix[x][y], visit[x][y], res);
        dfs(matrix, visit, x+1, y, matrix[x][y], visit[x][y], res);
        dfs(matrix, visit, x, y-1, matrix[x][y], visit[x][y], res);
        dfs(matrix, visit, x, y+1, matrix[x][y], visit[x][y], res);

    }
};