/* 806. Number of Lines To Write String
 * A straightforward solution, two pointers: line and idx,
 * line represents current lines needed, idx represents current pointer of the current line
 * simply adding new word and adding new line if needed.
 */

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, idx = 0;
        for(int i = 0; i < S.length(); i++){
            if(idx + widths[S[i] - 'a'] > 100){
                idx = widths[S[i] - 'a'];
                line++;
            }else{
                idx += widths[S[i] - 'a'];
            }
        }
        return {line, idx};
    }
};