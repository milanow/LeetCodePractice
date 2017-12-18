/* 479. Largest Palindrome Product
 * Intuitive solution, the candidate divider have a range of [lo, hi]
 * where hi = pow(10, n)-1 (eg: n = 3, hi = 999), lo = pow(10, n-1) (lo = 100)
 * checking palindrome number from highest possible number to see
 * if there is a possible way to make production through two n-digits number
 */

class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        
        int hi = (int)pow(10, n)-1, lo = (int)pow(10, n-1);
        long mx = (long)hi * (long)hi;
        
        int firstHalf = (int)(mx/(long)pow(10, n));
        bool found = false;
        long palindrome;
        
        while(!found){
            palindrome = createPalindrome(firstHalf);
            
            for(long i = hi; i >= lo; i--){
                if(palindrome / i > hi || palindrome / i < lo) break;
                if(palindrome%i != 0) continue;
                
                found = true;
                break;
            }
            firstHalf--;
        }
        
        return (int)(palindrome % 1337);
    }
    
    long createPalindrome(int half){
        string str = to_string(half);
        reverse(str.begin(), str.end());
        str = to_string(half) + str;
        return stol(str);
    }
};