/* 514. Freedom Trail
 * Thinking this problem step by step,
 * 1. every dialing costs 1 step, and before dialing, we need to move target character to 12:00 clock
 *    direction. Thus the final result equals: lengthOfKey + total distance
 * 2. Thinking of the total distance, since lengthOfKey is constant, to make final steps smaller
 *    We need to make distance of every dialing as less as possible. However, this is 
 *    not the situation to use Greedy Algorithm/strategy. Because every best choice tof dialing
 *    cannot guarantee the total is smallest. Thus we need to keep record every possible ways and
 *    find the smallest path.
 * dp[i] represents the smallest cost where the last dial chatacter is index of i in array ring
 * each iteration we calculate the previous index -> current index and find the shortest path
 * and save it into dp array
 */

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int klen = key.size();
        int rlen = ring.size();
        
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < rlen; i++){
            mp[ring[i]].push_back(i);
        }
        
        vector<int> dp(rlen, INT_MAX);
        dp[0] = 0;
        
        vector<int> lastIndex(1, 0);
        
        for(int i = 1; i <= klen; i++){
            vector<int> nextdp(rlen, INT_MAX);
            // new key index
            for(auto it: mp[key[i-1]]){
                // previous key index
                for(int j = 0; j < lastIndex.size(); j++){
                    int mindist = min((lastIndex[j] + rlen -it)%rlen,(it + rlen - lastIndex[j])%rlen) + dp[lastIndex[j]];
                    
                    nextdp[it] = min(nextdp[it], mindist);
                }
            }
            lastIndex = mp[key[i-1]];
            dp = nextdp;

        }
        
        int res = INT_MAX;
        for(int i = 0; i < rlen; i++){
            res = min(res, dp[i]);
        }
        return res + klen;
        
    }
};