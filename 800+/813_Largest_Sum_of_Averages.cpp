/* 813. Largest Sum of Averages
 * A dp+memory solution, dp[i][j] represents a subarray's argestSumOfAverages where ends at i, needs to divide into j groups.
 * Adding memory could avoid repeat calculation
 */

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));
        double sum = 0;
        for(int i = 1; i <= n; i++){
            sum += A[i-1];
            dp[i][1] = sum / i; 
        }
        return helper(A, dp, n, K);
    }
    
    double helper(vector<int>& A, vector<vector<double>>& mem, int end, int k){
        if(mem[end][k] > 0) return mem[end][k];
        double sum = 0;
        for(int i = end - 1; i >= 0; i--){
            sum += A[i];
            mem[end][k] = max(mem[end][k], helper(A, mem, i, k-1) + sum / (end - i));
        }
        return mem[end][k];
    }
};