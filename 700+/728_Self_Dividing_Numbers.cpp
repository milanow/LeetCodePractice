/* 728. Self Dividing Numbers
 * No tricks but brote force here
 */

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++){
            int j = i;
            while(j){
                int digit = j%10;
                if(digit == 0 || i % digit) break;
                j /= 10;
            }
            if(j == 0) res.push_back(i);
        }
        return res;
    }
};