/* 717. 1-bit and 2-bit Characters
 * The problem is actually asking how many bits of '1' before the last trailing '0'
 * if the number of '1' is even, then the last number must be one-bit character
 * odd -> false
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        bool res = true;
        for(int i = n-2; i >= 0 && bits[i] == 1; i--){
            res ^= true;
        }
        return res;
        
    }
};