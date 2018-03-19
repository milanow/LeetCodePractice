/* 409. Longest Palindrome
 * We can use up all letters to form a palindrome except
 * those letters with odd frequencies we can only left them one
 */

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        for(char c: s){
            mp[c]++;
        }
        bool odd = false;
        for(auto& p: mp){
            if(p.second & 1){
                res += p.second - 1;
                odd = true;
            }else{
                res += p.second;
            }
        }
        return res + (odd?1: 0);
    }
};
