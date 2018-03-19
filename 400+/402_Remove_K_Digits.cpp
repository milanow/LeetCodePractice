/* 402. Remove K Digits
 * To make the number as small as possible, the higher digits should be 
 * smaller than lower digits. However we can only remove k digits. As the 
 * higher digits is important to determine how big the number is. We eliminate
 * digits from highest digits. And try to eliminate those digits to maintain
 * an increasing sequence as long as possible. When we reach the lowest digit
 * or has eliminate k's digits. We stop and eliminating any leading zeroes.
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        int keep = len - k;
        string res;
        for(int i = 0; i < len; i++){
            while(res.size() > 0 && res.back() > num[i] && k > 0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        
        res.erase(keep, string::npos);
        
        int s = 0;
        while(s < res.length() && res[s] == '0') s++;
        res.erase(0, s);
        return res == ""? "0": res;
        
    }
};