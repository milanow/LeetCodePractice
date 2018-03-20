/* 424. Longest Repeating Character Replacement
 * A sliding window solution, detailed explaination below.
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int mx = 0, sz = s.length(), start = 0;
        for(int i = 0; i < sz; i++){
            // Maintain a sliding window whose length can be reachable by modifying
            // at most k letters, which is (end - start + 1 - k)
            // So when new letter comes, and it has largest frequency in the window
            // It has to shrink to make the window valid
            if((mx = max(mx, ++count[s[i] - 'A'])) + k < i - start + 1){
                --count[s[start++] - 'A'];
            }
        }
        return sz - start;
    }
};