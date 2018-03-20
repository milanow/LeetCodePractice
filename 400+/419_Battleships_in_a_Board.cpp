/* 419. Battleships in a Board
 * We only count space ship when 'X' is the top/left corner of the spaceship
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int m = board.size();
        if(!m) return 0;
        int n = board[0].size();
        if(!n) return 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X' && (i==0 || board[i-1][j] == '.') && (j==0 || board[i][j-1] == '.')) cnt++;
            }
        }
        return cnt;
    }
};
