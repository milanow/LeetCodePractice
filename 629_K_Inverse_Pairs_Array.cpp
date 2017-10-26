/* 629. K Inverse Pairs Array
 * A dp solotion, imagine we have permutaion of 1...4, when add a '5', we have:
 * 5xxxx creates 4 new inverse pairs;
 * x5xxx creates 3 new inverse pairs;
 * ...
 * xxxx5 creates 0 new inverse pairs;
 * Thus we can conclude: if dp[i][j] represents the number of permutaions 1 to i with j inverse pairs
 * then dp[i][j] = dp[i-1][j] + dp[i-1][j-1] +...+ dp[i-1]dp[j-i+1];
 * note: j-i+1 may less than zero, we should only consider it when index is larger than zero
 */

class Solution {
    const int mod = pow(10, 9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j>=i){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};