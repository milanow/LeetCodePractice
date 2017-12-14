/* 461. Hamming Distance
 * comparing different digits to calculate the hamming distance
 */

public class Solution {
    public int HammingDistance(int x, int y) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            if(((x^y) & (1<<i)) != 0) res++;
        }
        return res;
    }
}