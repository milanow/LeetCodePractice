/* 625. Minimum Factorization
 * obviously, a number who can follow such rules whose divisors are 2 <= d <= 9
 * if we have two divisors, let's say 3 and 4, then we place smaller number ahead, which is 34
 * Following the rules, we firstly divide the target number by 9 and then 8,7,6...,2. to
 * after all divisors checked, if target number becomes 1, then no answer provided.
 */

class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10) return a;
        long res = 0;
        for(int i = 9, p = 0; i >= 2 && p < 10; --i){
            while(a % i == 0 && p < 10){
                res += i*pow(10, p++);
                a /= i;
            }
        }
        
        return a > 1 || res > INT_MAX? 0: res;
    }
};