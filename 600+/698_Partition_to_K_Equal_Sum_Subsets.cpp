/* 698. Partition to K Equal Sum Subsets
 * The problem can be solved by putting array of numbers into k buckets,
 * Then calculating the sum of buckets to see if it can be the target
 * Target can be calculated by sumOfArray / k
 * 
 * First sorting the array nums where greater number has small index
 * Because if a bucket if larger than target, we can ignore this condition
 * Trying larger number first can save time.
 *
 * In the end, if all buckets' sums are target, then return true
 */

class Solution {
    bool res = false;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = nums.size();
        if(k == n) return false;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % k) return false;
        int tar = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> buckets(k, 0);
        dfs(nums, tar, 0, buckets);
        return res;
    }
    
    void dfs(vector<int>& nums, int tar, int idx, vector<int>& buckets){
        if(res) return;
        if(idx >= nums.size()){
            res = true;
            return;
        }
        for(int i = 0; i < buckets.size(); i++){
            if(i < buckets.size() - 1 && buckets[i] == buckets[i+1]) continue;
            if(buckets[i] + nums[idx] > tar) continue;
            buckets[i] += nums[idx];
            dfs(nums, tar, idx+1, buckets);
            buckets[i] -= nums[idx];
        }
    }
};