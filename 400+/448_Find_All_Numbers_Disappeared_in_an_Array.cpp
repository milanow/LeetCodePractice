/* 448. Find All Numbers Disappeared in an Array
 * Placing all numbers from 1-n to slot 0-(n-1), 
 * Then checking where nums[i] != i+1, the i+1 is the missing number
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int i = 0;
        while(i < n){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else i++;
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) res.push_back(i+1);
        }
        return res;
    }
};