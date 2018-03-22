/* 442. Find All Duplicates in an Array
 * Putting all numbers with correct positions
 * Any duplicated number may not "find" their position
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else i++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1) res.push_back(nums[i]);
        }
        return res;
    }
};