/* 668. Kth Smallest Number in Multiplication Table
 * binary search, in every loop, check if current position has reached k
 */


public class Solution {
    public int FindKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int c = count(mid, m, n);
            
            if(c >= k) hi = mid;
            else lo = mid + 1;
        }
        return hi;
    }
    
    private int count(int v, int m, int n){
        int count = 0;
        for(int i = 1; i <= m; ++i){
            int tmp = Math.Min(v / i, n);
            count += tmp;
        }
        return count;
    }
}