/* 482. License Key Formatting
 * Filling new string in characters by reversed order or original string.
 * Inserting '-' when needed.
 * Reverse the whole string back
 */

public class Solution {
    public string LicenseKeyFormatting(string S, int K) {
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for(int i = S.Length - 1; i >= 0; i--){
            if(S[i] != '-'){
                if(cnt > 0 && cnt % K == 0){
                    sb.Append('-');
                }
                sb.Append(Char.ToUpper(S[i]));
                cnt++;
            }
        }
        
        var charArr = sb.ToString().ToCharArray();
        Array.Reverse(charArr);
        return new string(charArr);
    }
}