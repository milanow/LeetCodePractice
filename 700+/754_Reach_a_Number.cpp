/* 754. Reach a Number
 * First make target positive because the number line is symetirc
 * The sum of movement can be: sum = n * (1 + n) / 2
 * And the target might be 1)exactly equal to sum 2) larget or smaller
 * For 1) we just return n;
 * For 2) we can make it smaller and get a difference by sum - target
 * Now, if the difference is even, we can get a specific move to left (suppose 
 * at the beginning, all moves are to right), in this case sum = sum - 2*pickednumber
 * Since we can choose an arbitary move from 1 to n, so there must be a pickednumber
 * where 2*pickednumber = difference
 * else if the difference is odd, we need to make it even,
 * For this case we can add n+1, if n+1 is even, then we can continually add n+2 to make 
 * the difference even
 */

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0+sqrt(1.0 + 8.0*target)) / 2);
        long long sum = n * (n+1) / 2;
        if(sum == target) return n;
        long long res = sum - target;
        if(res&1){
            return n + ((n&1)? 2: 1);
        }else{
            return n;
        }
    }
};