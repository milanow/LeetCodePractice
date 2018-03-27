/* 794. Valid Tic-Tac-Toe State
 * The information we need to collect through the 9 cells are:
 * 1. number of 'X' and 'O'
 * 2. if 'X' has 3-line
 * 3. if 'O' has 3-line
 * Detailed explination in the comments
 */

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        // rule: numof(X) - numod(O) == 1 or 0;
        // X and O cannot reach 3-line at the same time
        int numx = 0, numo = 0;
        bool threex = false, threeo = false;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X'){
                    numx++;
                    
                    if(!threex){                    
                        // count row
                        if(j == 2 && board[i][1] == 'X' && board[i][0] == 'X') threex = true;
                        // count col
                        if(!threex && i == 2 && board[1][j] == 'X' && board[0][j] == 'X') threex = true;
                        // count diagonal
                        if(!threex && i == 2 && j == 2 && board[1][1] == 'X' && board[0][0] == 'X') threex = true;
                        // count anti-diagonal
                        if(!threex && i == 2 && j == 0 && board[1][1] == 'X' && board[0][2] == 'X') threex = true;
                    }
                }else if(board[i][j] == 'O'){
                    numo++;
                    if(!threeo){                    
                        // count row
                        if(j == 2 && board[i][1] == 'O' && board[i][0] == 'O') threeo = true;
                        // count col
                        if(!threeo && i == 2 && board[1][j] == 'O' && board[0][j] == 'O') threeo = true;
                        // count diagonal
                        if(!threeo && i == 2 && j == 2 && board[1][1] == 'O' && board[0][0] == 'O') threeo = true;
                        // count anti-diagonal
                        if(!threeo && i == 2 && j == 0 && board[1][1] == 'O' && board[0][2] == 'O') threeo = true;
                    }
                }
            }
        }
        
        if(numx - numo > 1 || numx - numo < 0) return false;
        if(threeo && numx > numo) return false;
        if(threex && numx == numo) return false;
        if(threex && threeo) return false;
        
        return true;
    }
};