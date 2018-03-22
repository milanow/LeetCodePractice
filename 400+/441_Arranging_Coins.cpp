/* 441. Arranging Coins
 * A math problem, solved with "quadratic equation", the coins needed to form staircase
 * is: sum = (n+1)*n/2, and sum - n < 0.
 * for f(x) = 1/2*x^2 + 1/2*x - n < 0
 * the cloest root can be calculated by -1/2 + sqrt((1/2)^2 + 4/2*n)
 * which is -0.5 + sqrt(0.25 + n * 2)
 */

class Solution {
public:
    int arrangeCoins(int n) {
        return floor(-0.5 + sqrt(0.25 + (double)n * 2));
    }
};