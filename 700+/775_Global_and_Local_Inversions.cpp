/* 775. Global and Local Inversions
 * This problem is actually asking whether this array has no pairs: i, j
 * where i < j - 1 && A[i] > A[j]
 * When iterating, we keep maintaning a 'leftmx' value represents that
 * the max value from 0 to index - 2, index refers to current iteration index
 * And see if leftmx is larger than current index
 */

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if(n <= 2) return true;
        int leftmx = A[0];
        
        for(int i = 2; i < n; i++){
            leftmx = max(leftmx, A[i-2]);
            if(leftmx > A[i]) return false;
        }
        return true;
    }
};