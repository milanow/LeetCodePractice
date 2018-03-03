/* 719. Find K-th Smallest Pair Distance
 * A binary search solution. For each iterations, we count how many
 * differences in the array is smaller or equal to mid(which is difference
 * we are finding). If the 'count' was larger than k, then the mid 
 * MUST smaller than our targer difference because the larger the difference
 * the larger the 'count'. However even if we find 'count' equals mid
 * we cannot ensure mid is the taget difference because 1) mid maybe cannot 
 * be calculated by pairs in array and 2) there might be smaller difference
 * whose 'count' also equals to k.
 * Therefore, when cnt < k, next low becomes mid+1, when cnt >= k, next high becomes
 * mid instead of "return mid" when cnt == k
 */

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = nums[n-1];
        while(lo < hi){
            int mid = (lo + hi) / 2, cnt = 0;
            for(int i = 0, j = 0; i < n; i++){
                while(j < n && nums[j] - nums[i] <= mid) j++;
                cnt += j-i-1;
            }
            if(cnt < k){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        return lo;
    }
};