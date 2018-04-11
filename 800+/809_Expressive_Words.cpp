/* 809. Expressive Words
 * A two-pointer solution, for each word, we use two pointer i & j to indicate index in word and S
 * When a new character, say S[i] == 'c', found in S, we count how many 'c' aggregating together,
 * also count how many 'c' in word aggregating together, 
 * 3 conditions that make the word invalid:
 * 1) cntS == 1 && cntW != 1, means only one 'c' in S but more than one 'c' in W
 * 2) cntS == 2 && cntW != 2, means only two 'c' in S but in word it is not the same count,
 *   since 2 is not counted as "extra repeating"
 * 3) cntW > cntS, also cannot be countered as extra repeating
 */

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        int slen = S.length();
        for(string& word: words){
            int i = 0, j = 0;
            while(i < slen && j < word.length()){
                if(S[i] != word[j]) break;
                
                int cntS = 1, cntW = 1;
                // counting how many same characters in S
                while(i < slen - 1 && S[i] == S[i+1]){
                    i++;
                    cntS++;
                }
                while(j < word.length() - 1 && word[j] == word[j+1]){
                    j++;
                    cntW++;
                }
                if(cntS == 1 && cntW != 1) break;
                if(cntS == 2 && cntW != 2) break;
                if(cntW > cntS) break;
                i++;
                j++;
                
            }
            if(i == slen && j == word.length()) res++;
        }
        return res;
    }
};