/* 688. Knight Probability in Chessboard
 * More like a dfs solution, for each dfs recursion, check its possibilities of 
 * being inside board untial next move.
 * At the same time, record the calculation results to avoid repeated calculation
 */

class Solution {
    const vector<vector<int>> movedic{{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> mem(K+1, vector<vector<double>>(N, vector<double>(N, -1.0)));
        return helper(N, K, r, c, mem);
    }
private:
    double helper(int N, int k, int r, int c, vector<vector<vector<double>>>& mem){
        if(k == 0) return 1.0;
        if(mem[k][r][c] != -1.0) return mem[k][r][c];
        
        double p = 0;
        for(int i = 0; i < 8; i++){
            int newr = r+movedic[i][0];
            int newc = c+movedic[i][1];
            if(newr >= 0 && newr < N && newc >= 0 && newc < N){
                p += helper(N, k-1, newr, newc, mem);
            }
        }
        p /= 8.0;
        return mem[k][r][c] = p;
    }
};