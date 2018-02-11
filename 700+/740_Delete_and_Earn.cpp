/* 740. Delete and Earn
 * A sorted map to save elements and frequency of the elements
 * and continuelly add them deleted elements up by choosing delete current elements
 * or not. 
 * Much more like a dp process:
 * 1. if nums[i]-1 exists in map: dp[i] = max(dp[i-2]+nums[i], dp[i-1]) 
 * 2. else dp[i] = dp[i-1] + nums[i]
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(int n: nums){
            mp[n] += n;
        }
        int pre = 0, cur = 0;
        for(auto& p: mp){
            if(mp.find(p.first-1) == mp.end()){
                pre = cur;
                cur += p.second;
            }else{
                int tmp = max(pre + p.second, cur);
                pre = cur;
                cur = tmp;
            }
        }
        return cur;
    }
};