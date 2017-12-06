/* 484. Find Permutation
 * Thinking carefully about the question, the 
 * answer is actually clear. 
 * To have lexcicographically smallest permutaion of the arrangement
 * Thinking about 1, 2, 3,...,n, this is the array with smallest 
 * permutation with string "IIII..I", if there is a D appeared,
 * we need to put the small number before large number
 * Thus we just swtich the adjacent number and we can get a 'D'
 *
 * With this strategy in mind, we just need to arrange the array
 * starting from 123...9, and scanning the input stirng, whenever encounter
 * a 'D', we reverse corresponding digit(index) of number in the array
 */

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();
        vector<int> res(n+1);
        iota(begin(res), end(res), 1);
        
        int lastI = n;
        for(int idx = n-1; idx >= 0; idx--){
            if(s[idx] == 'I'){
                reverseVec(res, idx+1, lastI);
                lastI = idx;
            }
        }
        reverseVec(res, 0, lastI);
        return res;
    }
    
    void reverseVec(vector<int>& res, int start, int end){
        if(start >= end) return;
        int i = start, j = end;
        while(i < j){
            swap(res[i], res[j]);
            i++;
            j--;

        }
    }
};