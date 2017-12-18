/* 462. Minimum Moves to Equal Array Elements II
 * The median minimize the sum of deviations
 * Thus it gives the shortest distance when the point is at median
 * https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations
 */


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int mid = (int)nums.size() / 2;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += abs(nums[i] - nums[mid]);
        }
        return res;
    }
};