/* 739. Daily Temperatures
 * The problem can be transform to 'find out the next right number that larger than itself in the array'
 * To reach the target, we need to maintain a stack(or say window) whose bottom value is always
 * smaller than top value. 
 * e.g. stack: (bottom) 5 3 2 1 (top)
 * Checking from the beginning of array, for each iteration, pushing the indexes (coz need return the index)
 * into the stack and keep poping out those indexes that has found larger right number
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // find the next right number larger than itself
        stack<int> stk;
        int len = temperatures.size();
        vector<int> res(len, 0);
        stk.push(0);
        for(int i = 1; i < len; i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                res[stk.top()] = i - stk.top();
                stk.pop();
            } 
            stk.push(i);
        }
        return res;
    }
};