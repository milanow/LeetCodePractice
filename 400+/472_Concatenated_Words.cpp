/* 472. Concatenated Words
 * When tackling cancatenating strings problem, it is easier to consider as a dp problem
 * With a length of array whose size is str.length() + 1, checking which substring can be
 * deformed, and continue to check the dp array to see if there is a way to make current
 * string based on some substrings
 */

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> res;
        for(auto& w: words){
            int n = w.length();
            vector<bool> dp(n+1, false);
            dp[0] = true;
            for(int i = 0; i < n; i++){
                if(!dp[i]) continue;
                for(int j = i+1; j <= n; j++){
                    if(j - i < n && st.find(w.substr(i, j-i)) != st.end()) dp[j] = true;
                }
                if(dp[n]) {
                    res.push_back(w);
                    break;
                }
            }
        }
        return res;
    }
};