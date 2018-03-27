/* 466. Count The Repetitions
 * This solution is from Leetcode Forum
 * https://leetcode.com/problems/count-the-repetitions/discuss/95398/C++-solution-inspired-by-@70664914-with-organized-explanation
 */

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCnt(s2.length() + 1, 0);
        vector<int> nextIdx(s2.length() + 1, 0);
        int j = 0, cnt = 0;
        for(int k = 1; k <= n1; k++){
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == s2[j]){
                    j++;
                    if(j == s2.length()){
                        j = 0;
                        cnt++;
                    }
                }
            }
            repeatCnt[k] = cnt;
            nextIdx[k] = j;
            for(int s = 0; s < k; s++){
                if(nextIdx[s] == j){
                    int preRepeatCnt = repeatCnt[s];
                    int patternCnt = (n1 - s) / (k - s) * (repeatCnt[k] - repeatCnt[s]);
                    int sufRepeatCnt = repeatCnt[s + (n1-s)%(k-s)] - repeatCnt[s];
                    return (preRepeatCnt + patternCnt + sufRepeatCnt) / n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};