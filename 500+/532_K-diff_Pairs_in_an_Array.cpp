/* 532. K-diff Pairs in an Array
 * Save numbers into map and counting how many of them
 * in each pair in the hashmap, see if currentNumber+k resides in the hashmap
 * if k == 0 then mp[currentNumber] must larger than 1 to "pair"
 * if the resides in the hashmap, then increase the answer by one
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        
        int res = 0;
        for(auto p: mp){
            if(mp.find(p.first+k) != mp.end()){
                if(k != 0 || mp[p.first] > 1) res++;
            }
        }
        return res;
    }
};