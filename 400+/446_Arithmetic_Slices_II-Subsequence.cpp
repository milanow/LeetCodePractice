/* 446. Arithmetic Slices II - Subsequence
 * A dp solution, each dp[i][j] represents the number of arith sub-slice ends at i where
 * the difference is j.
 */
 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, int>> diffmp((int)A.size());
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < i; j++){
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int diff = A[i] - A[j];
                diffmp[i][diff]++;
                if(diffmp[j].find(diff) != diffmp[j].end()){
                    diffmp[i][diff] += diffmp[j][diff];
                    res += diffmp[j][diff];
                }
            }
        }
        return res;
    }
};