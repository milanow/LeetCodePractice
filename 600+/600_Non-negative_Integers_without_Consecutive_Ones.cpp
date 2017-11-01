/* 600. Non-negative Integers without Consecutive Ones
 * f[32] represents fibonacci array
 * for any bit, say 5, from 00000 to 11111, it has two ranges, one is from 00000 to 01111
 * and 10000 to 10111 (coz 11000 not valid), which means f[5] = f[4]+f[3];
 * Thus f is a fibonacci array.
 * For any number num, we calculate it from the highest bit, if it is a '1' bit, then the ans
 * should be added by f[k] where k is the kth bits in an integer.
 */

class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < 32; ++i){
            f[i] = f[i-1] + f[i-2];
        }
        int k = 30, ans = 0, pre_bit = 0;
        while(k >= 0){
            if(num&(1<<k)){
                ans += f[k];
                if(pre_bit) return ans;
                pre_bit = 1;
            }else{
                pre_bit = 0;
            }
            --k;
        }
        return ans+1;
    }
};