/* 792. Number of Matching Subsequences
 * A waiting array to put all words current matching indexes
 * iterating S to advance each word in waiting
 * When a word reaches end, then this word is subsequence of string S
 */

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> waiting[128];
        int res = 0;
        for (int i = 0; i < words.size(); i++)
            waiting[words[i][0]].emplace_back(i, 1);
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                if(it.second < words[it.first].size()){
                    waiting[words[it.first][it.second++]].push_back(it);
                }else{
                    res++;
                }
            }
        return res;
    }
};