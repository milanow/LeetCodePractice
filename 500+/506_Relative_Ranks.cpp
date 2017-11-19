/* 506. Relative Ranks
 * Use a sorted map to record score as key, index as value
 * Traverse the map to put ranks information into result array
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        
        vector<string> res(static_cast<int>(nums.size()));
        int rank = 1;
        for(auto it = mp.rbegin(); it != mp.rend(); it++, rank++){
            if(rank == 1){
                res[it->second] = "Gold Medal";
            }else if(rank == 2){
                res[it->second] = "Silver Medal";
            }else if(rank == 3){
                res[it->second] = "Bronze Medal";
            }else{
                res[it->second] = to_string(rank);
            }
        }
        return res;
    }
};