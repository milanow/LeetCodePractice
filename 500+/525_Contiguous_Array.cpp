/* 525. Contiguous Array
 * Save the difference of zeros & ones as we search through the array
 * If we found the difference has appear before (appeared in hashmap)
 * The subarray's, where made from previous index to current index,
 * ones and zeros are equal.
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int mxlen = 0, ones = 0, zeros = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeros++;
            }else{
                ones++;
            }
            
            if(mp.find(zeros-ones) != mp.end()){
                mxlen = max(mxlen, i-mp[zeros-ones]);
            }else{
                mp[zeros-ones] = i;
            }
        }
        return mxlen;
    }
};