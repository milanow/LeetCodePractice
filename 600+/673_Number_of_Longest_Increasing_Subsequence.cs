/* 673. Number of Longest Increasing Subsequence
 * This is a ap solution, 2 dp arrays recording the maxlen and count of current subsequence ends 
 * with indexed chracter. The array grows as new number can be added behind (nums[i] > nums[j])
 */ 

public class Solution {
    public int FindNumberOfLIS(int[] nums) {
        int n = nums.Length;
        int maxLen = 1, ans = 0;
        int[] len = new int[n];
        int[] cnt = new int[n];
        for(int i = 0; i < n; ++i){
            len[i] = 1;
            cnt[i] = 1;
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    if(len[j]+1 > len[i]){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }else if(len[j]+1 == len[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = Math.Max(maxLen, len[i]);
        }
        
        for(int i = 0; i < n; ++i){
            if(len[i] == maxLen) ans += cnt[i];
        }
        return ans;
    }
}