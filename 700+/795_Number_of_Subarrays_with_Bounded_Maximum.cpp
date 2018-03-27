/* 795. Number of Subarrays with Bounded Maximum
 * Numbers that are smaller than L can also be in the subarray by pairing
 * with other numbers who below [L, R], but 
 * numbers that are larer than R are definitely not in the subarray
 * 
 * So in summary we need to count out the blocks where all elements in
 * subarray are smaller or equal than R.
 * Then in the subarray, eliminating subarrays whoes numbers are all numbers 
 * smaller than L.
 */

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0;
        int start = -1, len = A.size();
        for(int i = 0; i < len; i++){
            if(A[i] > R){
                start = i;
            }else{
                res += i - start;
                if(A[i] < L){
                    int cnt = 1;
                    while(i < len - 1 && A[i+1] < L){
                        i++;
                        res += i - start;
                        cnt++;
                    }
                    res -= (1 + cnt)*cnt / 2;
                }
            }
        }
        // res += len - start;
        return res;
    }
};