/* 548. Split Array with Equal Sum
 * More like a math solution,
 * i+1,j,k are the three indexes,
 * when we found subarray's sum to i equal subsum from j to end
 * we found two subarray have equal sum, the next step is just find in the middle array
 * to see if there is a valid index can divide middle array to two subarray with same 
 * sum
 */

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int i, j, s = 0, len = nums.size();
        if(len < 7) return false;
        vector<int> sums(len, 0);
        for(int cnt = 0; cnt < len; cnt++){
            s += nums[cnt];
            sums[cnt] = s;
        }
        
        int total = sums.back();
        for(j = len-2; j >= 5; j--){
            for(i = 0; i <= j - 5; i++){
                if(total == sums[i] + sums[j]){
                    int tar = total - 4*sums[i] - nums[i+1] - nums[j];
                    for(int k = i+3; k < j-1; k++){
                        if(nums[k] == tar) return true;
                    }
                }
            }
        }
        return false;
    }
};