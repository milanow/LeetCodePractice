/* 744. Find Smallest Letter Greater Than Target
 * No explanation
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        unordered_set<char> st(letters.begin(), letters.end());
        int mn = INT_MAX;
        for(char c: st){
            mn = min(mn, (c > target? c: c + 26) - target);
        }
        return static_cast<char>((mn + target) > 'z'? (mn + target - 26): mn + target);
    }
};