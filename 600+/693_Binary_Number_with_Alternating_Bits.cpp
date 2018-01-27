/* 693. Binary Number with Alternating Bits
 * eg: n = 1010101
 *   n/2 = 0101010
 * n^n/2 = 1111111
 *    +1 =10000000
 *  & op = 0
 * the alternating bits value should always be 1010...101 or 1010...10
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/2) & (n+1));
    }
};