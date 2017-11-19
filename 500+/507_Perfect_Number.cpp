/* 507. Perfect Number
 * Simply add all numbers except itself to see if the sum equals itself
 * Note, we only need to check numbers where number*number <= num
 * When number = sqrt(num), number should only be added once
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0) return false;
        if(num == 1) return false;
        int sum = 1;
        int i;
        for(i = 2; i*i < num; i++){
            if(num % i == 0){
                sum += i;
                sum += num / i;
            }
        }
        if(i*i == num) sum += i;
        return sum == num;
    }
};