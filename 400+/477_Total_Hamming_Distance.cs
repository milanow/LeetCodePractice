/* 477. Total Hamming Distance
 * Checking each digits that how many '0's and '1's in total, the distance need
 * to be added is actually numOfZero*numOfOne. Iteratively checking each digit and eliminate
 * that digit by >> 1 (moving to the right) until all numbers in nums become zero
 */

public class Solution {
    public int TotalHammingDistance(int[] nums) {
        int n = nums.Length;
        if(n < 2) return 0;
        int res = 0;
        int[] tmp = new int[2];
        while(true){
            int cnt = 0;
            tmp[0] = 0;
            tmp[1] = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == 0) cnt++;
                tmp[nums[i] % 2]++;
                nums[i] >>= 1;
            }
            res += tmp[0]*tmp[1];
            if(cnt == n) return res;
        }
        return res;
    }
}