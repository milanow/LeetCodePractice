/* 410. Split Array Largest Sum
 * Binary search. canSplit function calculates if "mid" can be sumed up by numbers in nums
 * If when target is reached, a "cut" is performed to cut out a subarray.
 * If cuts is not enough, then the target, aka mid, cannot be reached. Then left = mid+1
 * because mid cannot be reached. If it can be reached, then we assign right = mid(not mid-1 because
 * mid can be reached) to find out possible smaller target
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for(int n: nums){
            left = max(left, (long long)n);
            right += n;
        }
        
        while(left < right){
            auto mid = left + (right - left) / 2;
            if(canSplit(nums, m-1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
private:
    long long canSplit(vector<int>& nums, int cuts, long long m){
        long long sum = 0;
        for(int n: nums){
            if(sum + n <= m) sum += n;
            else{
                // need more cuts to reach smallest subarrays' sums: m
                if(--cuts < 0) return false;
                sum = n;
            }
        }
        return true;
    }
};