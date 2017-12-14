/* 467. Unique Substrings in Wraparound String
 * Having a letter map letters int[26]
 * each number in the array represents the max length of substring which ends at
 * index + 'a' character. 
 */

public class Solution {
    public int FindSubstringInWraproundString(string p) {
        int[] letters = new int[26];
        int res = 0, len = 0;
        for(int i = 0; i < p.Length; i++){
            int cur = p[i] - 'a';
            if(i > 0 && p[i-1] != (cur + 26 - 1)%26 + 'a') len = 0;
            len++;
            if(len > letters[cur]){
                // number of strs that end at character: cur+'a'
                res += len - letters[cur];
                letters[cur] = len;
            }
        }
        return res;
    }
}