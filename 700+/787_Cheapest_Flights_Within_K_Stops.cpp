/* 787. Cheapest Flights Within K Stops
 * A typical dp problem. dp[i][j] represents the cheapest price to i with j steps
 * Firstly, convert current K from stop to step by adding 1
 * We gradually increase the step and for each step we iterate through the whole flights
 * and update the cheapest price to reach the destination until K steps.
 * return dp[dst][K] in the end
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // represeting step not stop now
        const int MAX = 1000000;
        K++;
        vector<vector<int>> dp(n, vector<int>(K+1, MAX));
        dp[src][0] = 0;
        for(int i = 1; i <= K; i++){
            // save previous results
            for(int j = 0; j < n; j++){
                dp[j][i] = dp[j][i-1];
            }
            for(auto& v: flights){
                dp[v[1]][i] = min(dp[v[1]][i], dp[v[0]][i-1] + v[2]);
            }
        }
        return dp[dst][K] == MAX? -1: dp[dst][K]; 
    }
};