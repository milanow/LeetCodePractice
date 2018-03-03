/* 790. Domino and Tromino Tiling
 * There are 3 different components can be seen to form up 2*N long board
 * 1. X
 *    X
 * 2. XX
 *    YY    
 * 3. XXY
 *    XYY
 * and for 3 it can be flipped over along axis, as dp[i] represents the ways to
 * form 2*i board, so
 * dp[i] = dp[i-1] + dp[i-2] + 2*(dp[i-3] + dp[i-4] +...+ dp[0]);
 * dp[i-1] = dp[i-2] + dp[i-3] + 2*(dp[i-4] + dp[i-5] +...+ dp[0]);
 * dp[i] - dp[i-1] = dp[i-1] + dp[i-3]; 
 * dp[i] = 2*dp[i-1] + dp[i-3];
 */

class Solution {
public:
    int numTilings(int N) {
        int md = 1e9 + 7;
        if(N == 1) return 1;
        if(N == 2) return 2;
        if(N == 3) return 5;
        vector<long long> dp(N+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= N; i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i] %= md;
        }
        return dp[N];
    }
};