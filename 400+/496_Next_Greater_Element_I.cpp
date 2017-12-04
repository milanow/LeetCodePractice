/* 496. Next Greater Element I
 * Use a hashmap to record the next great element in nums.
 * picking out what we need in hashmap since findNums is a subset of nums
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int len1 = findNums.size();
        int len2 = nums.size();
        
        unordered_map<int, int> all;

        stack<int> stk;
        for(int i = 0; i < len2; i++){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                all[nums[stk.top()]] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        vector<int> res(len1, -1);
        for(int i = 0; i < len1; i++){
            if(all.find(findNums[i]) != all.end()){
                res[i] = all[findNums[i]];
            }
        }
        return res;
    }
};