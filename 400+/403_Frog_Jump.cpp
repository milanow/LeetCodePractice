/* 403. Frog Jump
 * Memory + dp solution. For each recursion, bringing with k steps of last move and its
 * current position, we explore which stones frog can jump to and remember the status
 * formed up by pos and k, in case we have calculate (k, pos) before to save time preventing
 * calculating it again. Key is pos | k << 11 because pos can never be larger than 2^11
 * This key can ensure its uniqueness. 
 */

class Solution {
    unordered_map<int, bool> dp;
public:
    bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
        // sizeof(stones) < 1100 < 2048 == 2^11
        int key = pos | k << 11;
        if(dp.find(key) != dp.end()) return dp[key];
        
        for(int i = pos + 1; i < stones.size(); i++){
            int gap = stones[i] - stones[pos];
            if(gap < k-1){
                continue;
            }
            if(gap > k+1){
                return dp[key] = false;
            }
            if(canCross(stones, i, gap)){
                return dp[key] = true;
            }
        }
        return dp[key] = pos == stones.size()-1;
    }
};