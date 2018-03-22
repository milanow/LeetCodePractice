/* 440. K-th Smallest in Lexicographical Order
 * For each continuous two number (like 1, 2)
 * There would be intervals between them
 * These intervals are:
 * [1*10, 2*10]
 * [1*100, 2*100]
 * [1*1000, 2*1000]
 * ...
 * So we need to check which intervals the answer belongs to.
 * Supposing the starting numbers are 1, 2, 3..., 7, 8, 9
 * if intervals counting from 1, 2 is smaller than k
 * then we move it to 2, 3
 * else we go deep further to see which interval is belongs to
 * (go deep further means multiply larger power of 10)
 */

class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        for(--k; k > 0;){
            int cnt = 0;
            for(long long first = (long long)res, last = first+1; first <= n; first*=10, last*=10){
                cnt += static_cast<int>(min(static_cast<long long>(n+1), last) - first);
            }
            
            // current count is not enough, this won't happend in the first loop
            if(cnt <= k){
                res++;
                k -= cnt;
            }
            // goes into detail
            else{
                res *= 10;
                k--;
            }
        }
        return res;
    }
};