/* 611. Valid Triangle Number
 * A valid triangle should follow the rule: a + b > c, where a & b are the least two lines
 * Here comes our solotuin, sorts the vector first, then for each i,
 * we check if left + right larger than nums[i], then all numbers whose index is larger than left
 * can form triangle with right & nums[i], thus the count can add right-left up
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            int left = 0, right = i-1;
            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    count += right - left;
                    right--;
                }else{
                    left++;
                }
            }
        }
        return count;
    }
};