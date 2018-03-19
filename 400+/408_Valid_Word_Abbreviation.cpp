/* 408. Valid Word Abbreviation
 * A two-pointer solution, iterting two words to see any mismatch between them
 */

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int m = word.length(), n = abbr.length();
        while(i != m && j != n){
            if(word[i] == abbr[j]){
                i++;
                j++;
            }else if(abbr[j] >= '1' && abbr[j] <= '9'){
                int num = stoi(abbr.substr(j));
                i += num;
                while(j < n && abbr[j] >= '0' && abbr[j] <= '9') j++;
            }else break;
        }
        return i == m && j == n;
    }
};