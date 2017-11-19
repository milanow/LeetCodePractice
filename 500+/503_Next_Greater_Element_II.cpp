/* 503. Next Greater Element II
 * Cicular array problems can be solved by doubling the array
 * Traverse from left, if new element is larger than previous elements in stack
 * pop them untial current element is smaller or qeual than stack top element
 * then push every element for once (where i < n)
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res(n, -1);
        for(int i = 0; i < n*2; i++){
            while(!stk.empty() && nums[stk.top()] < nums[i % n]){
                res[stk.top()] = nums[i%n];
                stk.pop();
            }
            if(i < n) stk.push(i);
       }
        return res;
    }
};