/* 483. Smallest Good Base
 * To find the smallest good base is to find the longest 111...1
 * where n = base^0 + base^1 +...+ base^k 
 * since n <= 10^18, so n < 2^63, the idea is to check longest 111...1 (62 digits)
 * first and continually decreses the number of 1 till there is only one 1
 * 
 * The helper function uses a binary search to quick find out if it is possible to find
 * a base that can have that number of digits of 1.
 * the smallest base is 2, left = 2
 * the biggest base is pow(n, 1/d), becase n = base^0 + base^1 +...+ base^k => base^k < n
 */ 

public class Solution {
    public string SmallestGoodBase(string n) {
        ulong tar = Convert.ToUInt64(n);
        ulong x = 1;
        for(int i = 62; i >= 1; i--){
            if(tar > (x<<i)){
                ulong cur = helper(tar, i);
                if(cur != 0) return Convert.ToString(cur);
            }
        }
        return Convert.ToString(tar-1);
    }
    
    ulong helper(ulong tar, int d){
        double dtar = Convert.ToDouble(tar);
        ulong right = (ulong)(Math.Pow(dtar, 1f/d));
        ulong left = 2;
        while(left <= right){
            ulong mid = left + (right-left)/2;
            ulong sum = 1, cur = 1;
            for(int i = 1; i <= d; i++){
                cur *= mid;
                sum += cur;
            }
            if(sum == tar) return mid;
            if(sum > tar) right = mid - 1;
            else left = mid + 1;
        }
        return 0;
    }
}