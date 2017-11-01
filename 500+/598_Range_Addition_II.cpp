/* 598. Range Addition II
 * the max intergers are the ones being added most times
 * when performing ops, the "innermost" elements, which means 
 * the min coord elements can become the max intergers.
 * we just need to collect the min cow & min row in the ops
 * thus we can get the answer
 */

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minrow = m, mincol = n;
        for(int i = 0; i < ops.size(); ++i){
            m = min(m, ops[i][0]);
            n = min(n, ops[i][1]);
        }
        return m*n;
    }
};