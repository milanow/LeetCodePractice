/* 634. Find the Derangement of An Array
 * a dp qustion, dp[i] represents the amount of dearrangement
 * for the first element, let's say: 1, it has n-1 places to place (dats why comes *(i-1))
 * for the ith element, it has two choices,
 *     1. it's been placed at first place, then dp[i] = dp[i-2], since the left i-2 elements
 *        has i-2 places to place, the restriction for one element is "dont place on it's own number"
 *     2. it's not been placed at first place, then dp[i] = dp[i-1], since the except for first element,
 *        the left i-1 places have i-1 places to place, the restriction for i is: "dont place on 1 instead of i",
 *        because 1 is placed on i
 * that's why dp[i] = (i-1)*(dp[i-1] + dp[i-2])
 */

class Solution {
public:
    int findDerangement(int n) {
        long res = n==1? 0: 1;
        long tmp1 = 0, tmp2 = 1;
        for(int i = 3; i <= n; ++i){
            res = ((i-1)*(tmp1+tmp2))%1000000007;
            tmp1 = tmp2;
            tmp2 = res;
        }
        return (int)res;
    }
};