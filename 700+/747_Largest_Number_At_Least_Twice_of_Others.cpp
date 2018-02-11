/* 747. Largest Number At Least Twice of Others
 * Find out the max number and the second max number in the array
 * And find if the division result is equal or larger than 2
 */

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = -1, mx2 = -1;
        int cand = -1;
        
        if(nums.size() == 1) return 0;
                
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mx){
                mx2 = mx;
                mx = nums[i];
                cand = i;
            }else if(nums[i] > mx2){
                mx2 = nums[i];
            }
        }
        
        if(mx == 0 || mx == -1) return -1;
        if(mx2 == 0) return cand;
        return (mx/mx2) >= 2? cand: -1;
        
    }
};