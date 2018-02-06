/* 714. Best Time to Buy and Sell Stock with Transaction Fee
 * A typical dp problem. See comments as explaination
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // p0 represents profits that has no stock, p1 represents profit that has stock
        int p0 = 0, p1 = INT_MIN;
        
        for(int p: prices){
            int tmp = p0;
            p0 = max(p0, p1+p);
            p1 = max(p1, p0-p-fee);
        }
        return p0;
    }
};