/* 476. Number Complement
 * Make the complement number from the lowest digit,
 * Checking each digits of the num, and do XOR opreating with 1 to see if 
 * the complement number should be '1' or '0' on that digit.
 */

public class Solution {
    public int FindComplement(int num) {
        int res = 0, digit = 1;
        while(num > 0){
            res += (num%2 ^ 1) * digit;
            digit *= 2;
            num /= 2;
        }
        return res;
    }
}