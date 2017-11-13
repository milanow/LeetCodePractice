/* 516. Longest Palindromic Subsequence
 * A dp solution. dp[i][j] represents the longest subsequence length of a substring s
 * tarts at j with i length
 * dp[i][j] = 
 *     if s[j] == s[i+j-1], it represents at last last step dp[i-2][j+1] can add two
 *     same characters to make subsequence longer, so it is 2+dp[i-2][j+1]
 *     if s[j] != s[i+j-1], it can only be one of dp[i-1][j] or dp[i-1][j+1]
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> v0(n), v1(n, 1), v2(n), *it0 = &v0, *it1 = &v1, *it2 = &v2;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j + i <= n; j++){
                it0->at(j) = s[j] == s[i+j-1]? 2+it2->at(j+1): max(it1->at(j), it1->at(j+1));
            }
            swap(it2, it1);
            swap(it1, it0);
        }
        return it1->at(0);
    }
};