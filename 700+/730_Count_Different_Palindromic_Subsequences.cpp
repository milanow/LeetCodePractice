/* 730. Count Different Palindromic Subsequences
 * A typical dp problem, let dp[i][j][k] represents substring, who starts at i and chatacter
 * k("abcd" accoutding to the description) with length j, has dp[i][j][k] number of 
 * palindrome subsequence.
 * For every itreation, we check the new starting character S[i], c represents one of character
 * in "abcd":
 * 1. if S[i] != c, then dp[i][j][c] = dp[i+1][j-1][c] // ignore the first character 
 * 2. if S[i+j-1] != c, then dp[i][j][c] = dp[i][j-1][c] // ignore the last characrer
 * 3. else then dp[i][j][c] = dp[i+1][j-2]["abcd"] + 2, where 2 represents 
 *    palindrome: "c" and "cc".
 */

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        const int mod = 1e9 + 7;
        int n = S.length();
        vector<map<char, int>> cnt(n), cnt1(n), cnt2(n);
        long long res = 0;
        for(int len = 1; len <= n; len++, cnt2 = cnt1, cnt1 = cnt){
            for(int i = 0; i+len <= n; i++){
                for(char c: "abcd"){
                    if(len == 1) cnt[i][c] = S[i] == c;
                    else if(S[i] != c) cnt[i][c] = cnt1[i+1][c];
                    else if(S[i+len-1] != c) cnt[i][c] = cnt1[i][c];
                    else{
                        // this 2 palindrome is: "c" and "cc", where c stands a/b/c/d
                        cnt[i][c] = 2;
                        for(char cc: "abcd") (cnt[i][c] += cnt2[i+1][cc]) %= mod;
                    }
                }
            }
        }
        for(char c: "abcd"){
            (res += cnt[0][c]) %= mod;
        }
        return res;
    }
};