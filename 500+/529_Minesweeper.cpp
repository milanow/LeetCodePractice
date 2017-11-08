/* 529. Minesweeper
 * A typical DFS problem,
 * We can only step further (continuelly do DFS) only if current cell is 'E'
 */

class Solution {
    const vector<vector<int>> dirs{{0,1},{0,-1},{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        dfs(board, click[0], click[1]);
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y] != 'E') return;
        
        int m = board.size();
        int n = board[0].size();
        
        int mineadj = 0;
        for(int i = 0; i < 8; i++){
            int newx = x + dirs[i][0];
            int newy = y + dirs[i][1];
            
            if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
            if(board[newx][newy] == 'M'){
                mineadj++;
            }
        }
        
        if(mineadj > 0) board[x][y] = static_cast<char>(mineadj + '0');
        else{
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++){
                int newx = x + dirs[i][0];
                int newy = y + dirs[i][1];
                
                if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
                dfs(board, newx, newy);
            }
        }
    }
};