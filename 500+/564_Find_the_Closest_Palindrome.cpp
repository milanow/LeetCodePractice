/* 564. Find the Closest Palindrome
 * There are total 5 candidates
 * Say original number has 8 digits: XXXXYYYY
 * The upper and lower bound of two palindrome number is: 1 0000 0001 and 999 9999
 * Secondly, to make the number palindrome and closer to the original number,
 * we need to adjust lower digits rather than higher digits.
 * Thus if we have 8 digits, we need to adjust 4 lower digits: YYYY
 * "half" represents the higher 4 digits, the lowest digit of "half" can be
 * added [-1,1] to be a palindrome, such that we have 3 more candidates(as string pp 
 * in the code).
 * Then iterate the set(note it's not an unordered_set), a set with order from small to large
 * If we found a closer palindrome, then replace it for a better answer
 */

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        set<long> cands;
        if(len == 0) return "";
        cands.insert((long)(pow(10, len) + 1));
        cands.insert((long)(pow(10, len-1) -1));
        
        long half = stol(n.substr(0, (len+1)/2));
        for(long i = -1; i <= 1; ++i){
            string p = to_string(half + i);
            string pp = p + string(p.rbegin() + (len%2), p.rend());
            cands.insert(stol(pp));
        }
        
        long num = stol(n), mindiff = LONG_MAX, val = -1;
        cands.erase(num);
        for(long l: cands){
            long diff = labs(l - num);
            if(mindiff > diff){
                mindiff = diff;
                val = l;
            }
        }
        return to_string(val);
    }
    
};

