/* 405. Convert a Number to Hexadecimal
 * A digit of hex represents four bits, so we just need to calculate every 4 bits
 * by pasring out the last 4 digits and add it to our final hex.
 * To parse out 4 bits cwe can use num & 0xf, then shift 4 bits to access next 4 bits.
 * Note: we need a counter here because for positive number, computer may add
 * '0' to as its first digit when shifting to right, for negative number, it would be
 * '1' instead of '0'. So if not using counter i++, it may cause an infinite loop
 */

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        const vector<char> dict = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res;
        int i = 0;
        while(num != 0 && i++ < 8){
            res.insert(res.begin(), dict[num & 0xf]);
            num >>= 4;
        }
        return res;
    }
};