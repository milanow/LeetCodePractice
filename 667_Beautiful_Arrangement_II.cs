/* 667. Beautiful Arrangement II
 * There are possibly many arrangements meet the requirement, but we just need to find one
 * consider such arrangement: 1, n, 2, n-1, 3, n-2,...We find out every intervals is a new difference
 * so when generate k-1's difference, we just put rest numbers as increasing/decreasing order,
 * in which way we can only have one difference - 1
 */

public class Solution {
    public int[] ConstructArray(int n, int k) {
        int[] ans = new int[n];
        int large = n, small = 1;
        bool smallturn = true;
        
        for(int i = 0; i < n; ++i){
            ans[i] = smallturn? small++: large--;
            if(k > 1){
                k--;
                smallturn = !smallturn;
            }
        }
        return ans;
    }
}