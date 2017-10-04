/* 660. Remove 9
 * The core of the problem is trans decimal to novenary number
 */

public class Solution {
    public int NewInteger(int n) {
        int b = 1;
        int res = 0;
        while(n != 0){
            res += n % 9 * b;
            n /= 9;
            b *= 10;
        }
        return res;
    }
}