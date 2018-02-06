/* 718. Maximum Length of Repeated Subarray
 * DP problem. dp[j] represents max (same) subarray of B in A, starting at j
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        vector<int> dp(nb+1, 0);
        int mx = 0;
        for(int i = na-1; i >= 0; i--){
            for(int j = 0; j < nb; j++){
                mx = max(mx, dp[j] = A[i] == B[j]? dp[j+1]+1: 0);
            }
        }
        return mx;
    }
};