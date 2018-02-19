/* 771. Jewels and Stones
 * check each characters in stones iteratively
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> dict(J.begin(), J.end());
        int res = 0;
        for(char c: S){
            if(dict.find(c) != dict.end()) res++;
        }
        return res;
    }
};