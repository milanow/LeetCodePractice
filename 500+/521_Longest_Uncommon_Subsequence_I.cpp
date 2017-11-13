/* 521. Longest Uncommon Subsequence I 
 * when finding longest uncommon
 * subsequence, the key is if two strings are equal.
 */

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        int lena = a.length(), lenb = b.length();
        return lena > lenb? lena: lenb;
    }
};