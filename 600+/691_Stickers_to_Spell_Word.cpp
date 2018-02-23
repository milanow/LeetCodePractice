/* 691. Stickers to Spell Word
 * This problem can be solved by backtracking+memorization
 * First, save all stickers by counting frequency of characters 
 * and saving it to a int[26] array (vector<int>(26));
 * Then For each recursion, we pick a sticker from all stickers and
 * subtract the characters which the sticker & target string both have.
 * And form a new string by target's remainning characters to pass down 
 * to deeper recursion.
 *
 * Note: memorization, since some target string we might have calculated before
 * a diction which saves the result can save a lot of time.
 * Note2: We pick sticker by a simple rule: it can at least have the first character
 * of our target. Because in the end we have to find out the stiker which has the first
 * character of target, and the stikers library doesn't change. So add such limitaion
 * can reduce searching space.
 */

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> mp(n, vector<int>(26, 0));
        unordered_map<string, int> mem;
        for(int i = 0; i < stickers.size(); i++){
            for(char c: stickers[i]) mp[i][c-'a']++;
        }
        mem[""] = 0;
        return helper(mp, mem, target);
    }
    
private:
    int helper(vector<vector<int>>& mp, unordered_map<string, int>& dp, string str){
        if(dp.find(str) != dp.end()) return dp[str];
        vector<int> dict(26, 0);
        for(char c: str) dict[c-'a']++;
        int n = mp.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            // since we have to find a str that can fit str[0] now or in the future, we can do it here
            // to reduce some candidates
            if(mp[i][str[0]-'a'] == 0) continue;
            string s;
            for(int j = 0; j < 26; j++){
                if(dict[j] > mp[i][j]) s += string(dict[j] - mp[i][j], j+'a');
            }
            int subans = helper(mp, dp, s);
            if(subans != -1) ans = min(ans, subans+1);
        }
        dp[str] = ans == INT_MAX?-1: ans;
        return dp[str];
    }
};