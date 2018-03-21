/* 438. Find All Anagrams in a String
 * Dynamically maintain a window whose size is same with string p
 * the window contains information about the frequency of each characters in the window
 * When the frequencies in window of stirng s matches frequencies in string p
 * THen we say we find an anagram.
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return vector<int>();
        vector<int> dictp(26, 0), dicts(26, 0), res;
        for(char c: p){
            dictp[c - 'a']++;
        }
        
        for(int i = 0; i < p.length(); i++){
            dicts[s[i] - 'a']++;
        }
        
        for(int i = p.length(); i < s.length(); i++){
            if(dicts == dictp){
                res.push_back(i - p.length());
            }
            dicts[s[i-p.length()] - 'a']--;
            dicts[s[i] - 'a']++;
        }
        if(dicts == dictp){
            res.push_back(s.length() - p.length());
        }
        return res;
    }
};