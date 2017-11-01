/* 561. Array Partition I
 * Sort the array
 * pairing them by 0 with 1, 2 with 3...2n-2 with 2n-1
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i % 2 == 0){
                res += nums[i];
            }
        }
        return res;
    }
};