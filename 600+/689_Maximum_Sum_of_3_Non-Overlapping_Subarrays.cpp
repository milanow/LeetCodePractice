/* 689. Maximum Sum of 3 Non-Overlapping Subarrays
 * My solution is straightforward, first of all, it is obviously a 
 * dp problem. Max sum of three subarrays can be divided into 1) two subarrays
 * and 2) one subarray. Max sum of two subarrays can be divided into two one-subarray
 * Thus I iteratively calculate the "one blocks dp" -> "two blocks dp" -> "three blocks dp"
 * ksum[i], k2sum[i], k3sum[i] represents the max sum of 1/2/3 blocks who has a block ends
 * at i. dp1[i], dp2[i], represents the max sum of 1/2/3 who is the subarray of nums from 0 to i
 * cand1, cand2, cand3 are used to record block indexes of dp1, dp2, dp3
 */
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ksum(n, 0), dp1(n, 0), k2sum(n, 0), dp2(n, 0), k3sum(n, 0), dp3(n, 0);
        vector<int> cand1(n, 0), cand3(3, 0);
        vector<vector<int>> cand2(n, vector<int>(2, 0));
        
        for(int i = k-1; i < n; i++){
            for(int j = 0; j < k; j++){
                ksum[i] += nums[i - k + 1 + j];
            }
        }
        
        dp1[k-1] = ksum[k-1];
        cand1[k-1] = k-1;
        for(int i = k; i < n; i++){
            if(ksum[i] > dp1[i-1]){
                cand1[i] = i;
                dp1[i] = ksum[i];
            }else{
                cand1[i] = cand1[i-1];
                dp1[i] = dp1[i-1];
            }
        }
        
        for(int i = 2*k-1; i < n; i++){
            k2sum[i] = ksum[i] + dp1[i-k];
        }
        
        dp2[2*k-1] = k2sum[2*k-1];
        cand2[2*k-1][0] = cand1[k-1];
        cand2[2*k-1][1] = 2*k-1;
        for(int i = 2*k; i < n; i++){
            if(k2sum[i] > dp2[i-1]){
                cand2[i][0] = cand1[i-k];
                cand2[i][1] = i;
                dp2[i] = k2sum[i];
            }else{
                cand2[i][0] = cand2[i-1][0];
                cand2[i][1] = cand2[i-1][1];
                dp2[i] = dp2[i-1];
            }            
        }
        
        for(int i = 3*k-1; i < n; i++){
            k3sum[i] = ksum[i] + dp2[i-k];
        }
        
        dp3[3*k-1] = k3sum[3*k-1];
        cand3[0] = cand2[2*k-1][0];
        cand3[1] = cand2[2*k-1][1];
        cand3[2] = 3*k-1;
        int curmax = dp3[3*k-1];
        for(int i = 3*k; i < n; i++){
            if(k3sum[i] > curmax){
                curmax = k3sum[i];
                cand3[0] = cand2[i-k][0];
                cand3[1] = cand2[i-k][1];
                cand3[2] = i;
            }
        }
        for(int i = 0; i < 3; i++){
            cand3[i] -= (k-1);
        }
        return cand3;
    }
};