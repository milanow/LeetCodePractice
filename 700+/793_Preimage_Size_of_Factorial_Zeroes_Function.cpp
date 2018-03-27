/* 793. Preimage Size of Factorial Zeroes Function
 * This solution is from Leetcode Forum, so I just paste it here
 * It is hard to explain this problem
 * https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/discuss/117631/C++-O(logn)-math-solution-with-explanation
 */

class Solution {
public:
    int preimageSizeFZF(int K) {
        int sum[13]={1};
        for (int i=1; i<13; i++) sum[i]=sum[i-1]*5+1;
        for (int i=12; i>=0; i--) {
            if (K/sum[i]==5) return 0;
            K=K%sum[i];
        }
        return 5;
    }
};