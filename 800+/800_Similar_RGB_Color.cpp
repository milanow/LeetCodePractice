/* 800. Similar RGB Color
 * The six digit of number can be actually divided into 3 groups of 2 digits, because
 * this dividing operation won't affect each others.
 * For each two digits group, there are actually only two candidates (smaller than ori &
 * larger than ori, e.g. 5f -> 55 or 66), by adding 8 and divide 17, we can determine we should
 * adding one or not (66 = adding one, 55 = not adding one).
 */

class Solution {
    const string hex = "0123456789abcdef";
    string helper(string num){        
        int hexnum = stoi(num, nullptr, 16);
        int tar = (hexnum + 8) / 17;
        string res;
        res.append(2, hex[tar]);
        return res;
    }
public:
    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
};CP