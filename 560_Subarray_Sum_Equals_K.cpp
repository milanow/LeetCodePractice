/* 560. Subarray Sum Equals K
 * Tips: the array n0,n1,n2...nn-1 of sum can always be saved by: s0, s1, s2...sn-1
 * where s0 = n0, s1 = n0 + n1, s2 = n0 + n1 + n2...sn-1 = n0 + n1+...+nn-1
 * This can support fast subarray sum retrieve.
 */ 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> mp;
        int cum = 0;
        mp[0]++;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cum += nums[i];
            cnt += mp[cum - k];
            mp[cum]++;
        }
        return cnt;
            
    
    }
};