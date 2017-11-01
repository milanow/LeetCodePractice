/* 568. Maximum Vacation Days
 * a dp solution, dp[i][j] represents the max vacations got if being at city i at week j
 */

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int mxdays = 0, N = days.size(), K = days[0].size();
        
        vector<vector<int>> dp(N, vector<int>(K, 0));
        for(int j = K-1; j >= 0; j--){
            for(int i = 0; i < N; ++i){
                // spent days in this week
                dp[i][j] = days[i][j];
                for(int i1 = 0; i1 < N && j != K-1; i1++){
                    // this ensure you cannot take one more flight in same day
                    // if you flied to some places, you must spend days there
                    if(flights[i][i1] || i == i1){
                        dp[i][j] = max(dp[i][j], days[i][j] + dp[i1][j+1]);
                    }
                }
                
                if(j == 0 && (i == 0 || flights[0][i])) mxdays = max(mxdays, dp[i][0]);
            }
        }
        return mxdays;
    }
};