/* 565. Array Nesting
 * Numbers from 0 to N-1 can be seperated into groups, which are numbers
 * forming up a cycle/nesting. 
 * My idea is simple, marking those groups out and see which one has the most elements
 * For each element in nums, we just nest down the element and find out group members
 * updating max length until all groups are found
 */
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int mxlen = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                int len = 1, next = nums[i];
                while(next != i){
                    visited[next] = true;
                    len++;
                    next = nums[next];
                }
                mxlen = max(len, mxlen);
            }
        }
        return mxlen;
    }
};