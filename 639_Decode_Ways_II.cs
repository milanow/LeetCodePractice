/* 639. Decode Ways II
 * DP solution. Each step dp[i] = dp[i-1]*ParseNum(s.Substring(i,1)) + dp[i-2]*ParseNum(s.Substring(i-1,2))
 * For parseNum function, we only need to deal with substring.size() == 1 or 2, details
 * can be easily represented by my code.
 */

public class Solution {
    const int modbase = 1000000007;
    
    public int NumDecodings(string s) {
        int n = s.Length;
        if(n == 0) return 0;
        long f1 = 1, f2 = Helper(s.Substring(0, 1));
        for(int i = 1; i < n; ++i){
            long f3 = (f2*Helper(s.Substring(i, 1))) + (f1*Helper(s.Substring(i-1, 2)));
            f1 = f2;
            f2 = f3%modbase;
        }
        return (int)f2;
    }
    
    private int Helper(string s){
        if(s.Length == 1){
            if(s[0] == '*') return 9;
            return s[0] == '0'? 0: 1;
        }
        
        if(s == "**"){
            return 15;
        }else if(s[1] == '*'){
            if(s[0] == '1') return 9;
            return s[0] == '2'? 6: 0;
        }else if(s[0] == '*'){
            return s[1] <= '6'? 2: 1;
        }else{
            int num = Int32.Parse(s);
            return num >= 10 && num <= 26?1: 0;
        }
    }
}