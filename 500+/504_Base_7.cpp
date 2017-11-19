/* 504. Base 7
 * a base 7 number means carrying when hitting 7
 */

class Solution {
public:
    string convertToBase7(int num) {
        int n = abs(num);
        string res = to_string(n%7);
        while(n /= 7) res = to_string(n%7) + res;
        return (num>=0?"":"-") + res;
    }
};