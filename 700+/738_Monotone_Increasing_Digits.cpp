/* 738. Monotone Increasing Digits
 * The key is to find the left most digit which is smaller than its left adjcent
 * digit. And filling the digit and its right side digits with '9'
 */

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // Once higher digit minus one, the lower digits can all be 9
        string ns = to_string(N);
        
        int sz = ns.size();
        int pos = sz;
        for(int i = sz-1; i > 0; i--){
            if(ns[i] < ns[i-1]){
                pos = i;
                ns[i-1] = static_cast<char>(ns[i-1] - 1);
            }
        }
        for(int i = pos; i < sz; i++) ns[i] = '9';
        return stoi(ns);
        
    }
};