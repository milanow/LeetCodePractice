/* 562. Longest Line of Consecutive One in Matrix
 * A typical dp solution, we only needs two lines of information, that is why I have
 * 8(4+4) length subarray for each element of one line.
 * indexes represent:
 * 0,4 : -> horizontal
 * 1,5 : \> diagnal
 * 2,6 : |> vertical
 * 3,7 : /> anti-diagnal
 * old & cur represents last cache and current cache
 */

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if(!m) return 0;
        int n = M[0].size();
        if(!n) return 0;
        
        // 0: horizontal, 1: diagnal, 2: vertical, 3: anti-diagnal
        int cur = 0, old = 1, mx = 0;
        vector<vector<int>> dp(n, vector<int>(8, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(M[i][j]){
                    dp[j][cur*4 + 0] = j == 0? 1: dp[j-1][cur*4+0] + 1;
                    dp[j][cur*4 + 1] = j == 0? 1: dp[j-1][old*4 + 1] + 1;
                    dp[j][cur*4 + 2] = dp[j][old*4 + 2] + 1;
                    dp[j][cur*4 + 3] = j == n-1? 1: dp[j+1][old*4+3] + 1;
                    for(int k = 0; k < 4; k++){
                        mx = max(mx, dp[j][cur*4 + k]);
                    }
                }else{
                    dp[j][cur*4 + 0] = dp[j][cur*4 + 1] = dp[j][cur*4 + 2] = dp[j][cur*4 + 3] = 0;
                }
            }
            cur = (cur+1)%2;
            old = (old+1)%2;
        }
        return mx;
    }
};