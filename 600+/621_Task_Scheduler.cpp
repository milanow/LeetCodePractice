/* 621. Task Scheduler
 * We need to minimize the 'idle' states as possible. The bottleneck is the most tasks
 * As same tasks cannot be done without n cool down. Thus we need to calculate the most tasks
 * And place them(A) as: A..n..A..n..A, and the rest tasks can fill in those blanks. However,
 * there can be more than one most tasks, where we have to place them(B): AB..n..AB..n..AB
 * thus the least intervals needed is: (mx-1)*(n+1) + mxcnt. Compare it with task amount. return the larger one
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int letters[26] = {0};
        int mx = 0;
        for(char& i: tasks){
            letters[i-'A']++;
            mx = max(mx, letters[i-'A']);
        }
        
        int mxcnt = 0;
        for(int i: letters){
            if(i == mx) mxcnt++;
        }
        
        int finalmx = (mx-1)*(n+1) + mxcnt;
        int len = tasks.size();
        return max(len, finalmx);
    }
};