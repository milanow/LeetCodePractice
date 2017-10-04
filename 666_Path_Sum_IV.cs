/* 666. Path Sum IV
 * the core idea is to store how many leaves a node will 'have' when calculating paths
 * So counting from the leaves, which is 1, with a bottom up method to calculate how many times
 * does this node would be added. Then calculating the final sum
 */

public class Solution {
    public int PathSum(int[] nums) {
        if(nums.Length < 1) return 0;
        var dict = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; ++i){
            dict.Add(nums[i]/10, 0);
        }
        
        for(int i = nums.Length-1, depth = nums[nums.Length-1]/100; i >= 0; --i){
            int d = nums[i]/100;
            int p = nums[i]/10 - d*10;
            
            if(d == depth){
                dict[nums[i]/10] = 1;
            }else{
                int sum = 0;
                sum += dict.ContainsKey((d+1)*10 + p*2-1)? dict[(d+1)*10 + p*2-1]: 0;
                sum += dict.ContainsKey((d+1)*10 + p*2)? dict[(d+1)*10 + p*2]: 0;
                dict[nums[i]/10] = sum == 0? 1: sum;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < nums.Length; ++i){
            ans += dict[nums[i]/10]*(nums[i]%10);
        }
        return ans;
    }
}