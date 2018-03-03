/* 727. Minimum Window Subsequence
 * My original solution to this problem is TLE. Because it has a O(m^2) complexity
 * The new solotion comes from leetcode's discussion, having a O(m*n) complexity
 * because n(length of T) is always smaller than m(langth of S).
 *
 * both solution are Dynamic Programming
 * The old solution dp[i][j] represents substring ends at index j of S with length i,
 * the integer shows how far the substring matches T, aka, the last index of
 * matched character of stirng T. When reaching T's length, it proves that we
 * have found the answer and return it immediately.
 *
 * The new solution, dp[i] represents the starting index of S that matches T
 */

class Solution {
public:
    string minWindow(string S, string T) {
        // int m = S.length(), n = T.length();
        // // dp[i][j] represents substring ends at index j of S with length i
        // vector<vector<int>> dp(m+1, vector<int>(m, 0));
        // int idx = 0;
        // for(int i = 1; i <= m; i++){
        //     for(int j = i-1; j < m; j++){
        //         int k = dp[i-1][j-1];
        //         dp[i][j] = S[j] == T[k]? k+1: k;
        //         if(dp[i][j] == n){
        //             return S.substr(j-i+1, i);
        //         }
        //     }
        // }
        // return "";
        
        int m = S.length(), n = T.length();
        vector<int> dp(m, -1);
        for(int i = 0; i < m; i++){
            if(S[i] == T[0]) dp[i] = i;
        }
        
        // Fill substring with starting index
        for(int j = 1; j < n; j++){
            int k = -1;
            vector<int> tmp(m, -1);
            for(int i = 0; i < m; i++){
                if(k != -1 && S[i] == T[j]) tmp[i] = k;
                if(dp[i] != -1) k = dp[i];
            }
            swap(tmp, dp);
        }
        
        int start = -1, len = INT_MAX;
        for(int i = 0; i < m; i++){
            if(dp[i] != -1 && i-dp[i]+1 < len){
                start = dp[i];
                len = i-dp[i]+1;
            }
        }
        return start == -1? "": S.substr(start, len);
        
    }
};