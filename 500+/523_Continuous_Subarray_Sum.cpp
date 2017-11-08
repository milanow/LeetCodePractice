/* 523. Continuous Subarray Sum
 * It is still a sub-sum problem since we are dealing with subarray(not sequence)
 * A hashset to store previous module, and save previous mod into the hashset
 * Since the problem requires at least length 2, thus we need to insert the mod value 
 * one iterator later
 */
 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int mod = k == 0? sum: sum%k;
            if(st.find(mod) != st.end()) return true;
            st.insert(pre);
            pre = mod;
        }
        return false;
    }
};