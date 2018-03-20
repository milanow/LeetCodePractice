/* 418. Sentence Screen Fitting
 * The solution is straight forward. Simply putting words into each rows directly and
 * to see how many sentences it can fits. The trick part is using an unordered_map to
 * memorize previous calculation to avoid repeating calculation/
 */

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        if(rows < 1 || cols < 1) return 0;
        int words = 0, len = sentence.size();
        int start = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < rows; i++){
            start = words % len;
            if(mp.find(start) == mp.end()){
                int cnt = 0, sz = 0;
                for(int j = start; sz < cols; j = (j+1)%len, cnt++){
                    if(sz + sentence[j].length() - 1 >= cols) break;
                    sz += sentence[j].length()+1;
                }
                words += cnt;
                mp[start] = cnt;
            }else{
                words += mp[start];
            }
        }
        return words / len;
    }
};