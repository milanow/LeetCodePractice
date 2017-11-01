/* 672. Bulb Switcher II
 * the 4 ops can only generate "3 bits difference = 8", thus after m= 3 & n=3 all the reaults are 8
 * thus we just need to list all condition smaller than m=3 & n=3
 */

public class Solution {
    public int FlipLights(int n, int m) {
        if(n == 0 || m == 0) return 1;
        if(n == 1) return 2;
        if(n == 2) return m == 1? 3: 4;
        if(m == 1) return 4;
        return m == 2? 7: 8;
    }
}