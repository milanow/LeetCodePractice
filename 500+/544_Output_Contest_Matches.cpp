/* 544. Output Contest Matches
 * Simulate what happened each rounds:
 * Considering a pair of parenthese as a result of match
 * Each rounds the number of teams may decrese to half of original number
 */

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ivec(n+1);
        for(int i = 1; i <= n; i++){
            ivec[i] = to_string(i);
        }
        
        while(n > 1){
            for(int i = 1, j = n; i <= n/2; i++, j--){
                ivec[i] = "(" + ivec[i] + "," + ivec[j] + ")"; 
            }
            n >>= 1;
        }
        return ivec[1];
    }
};