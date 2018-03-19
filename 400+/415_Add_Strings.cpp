/* 415. Add Strings
 * Added two number from lowest digits
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        string res;
        while(i >= 0 || j >= 0 || carry > 0){
            int n = 0;
            n += i >= 0? (num1[i--] - '0'): 0;
            n += j >= 0? (num2[j--] - '0'): 0;
            n += carry;
            
            carry = n/10;
            n %= 10;
            res = to_string(n) + res;
        }

        return res;
    }
};