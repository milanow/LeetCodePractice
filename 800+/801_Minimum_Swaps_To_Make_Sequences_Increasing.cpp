/* 801. Minimum Swaps To Make Sequences Increasing
 * A dp solution. 2 dp arrays represent swap or not swap current index between A & B
 * to make both array "increasing". Detailed explination in the comments
 * Note: index zero is always valid, because whatever zero index is, we just need to
 * make sure his next element in array is larger than it.
 */

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size(), res = 0;
        vector<int> swapdp(len, len), noswapdp(len, len);
        swapdp[0] = 1;
        noswapdp[0] = 0;
        for(int i = 1; i < len; i++){
            if(A[i] > A[i-1] && B[i] > B[i-1]){
                // We have swaped A[i-1] & B[i-1] before, so A[i] > A[i-1] actually means A[i] > B[i-1]
                // We need to swap them back
                swapdp[i] = swapdp[i-1] + 1;
                // No need to change noswap
                noswapdp[i] = noswapdp[i-1];
            }
            
            // Also need to check this condition, so it shound't be "else if"
            if(A[i] > B[i-1] && B[i] > A[i-1]){
                // We didn't swap at i-1, so we need to swap them here
                swapdp[i] = min(swapdp[i], noswapdp[i-1] + 1);
                // We swaped at i-1, so we don't need to swap them here
                noswapdp[i] = min(noswapdp[i], swapdp[i-1]);
            }
        }
        return min(swapdp.back(), noswapdp.back());
    }
};