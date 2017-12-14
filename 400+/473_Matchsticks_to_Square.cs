/* 473. Matchsticks to Square
 * First checking if the total length of square is mutiple of 4, if so calculating
 * the target length of side. Say "tar".
 * Before dfs, we sort the sticks in reversed order because in that way it saves the times
 * we try dfs. Reduced the number of branches.
 * Secondly we have a 4 sides buffer, try to put one stick on each sides
 * If it is larger than "tar" then we give up trying it. 
 * if one of the dfs branch can make a square, we return true directly.
 */

public class Solution {
    public class ReverseComp: IComparer<int>
    {
        public int Compare(int a, int b){
            return b.CompareTo(a);
        }
    }
    
    public bool Makesquare(int[] nums) { 
        Array.Sort(nums, new ReverseComp());
        
        int len = nums.Length;
        if(len < 4) return false;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
        }
        
        if(sum%4 != 0) return false;
        int tar = sum / 4;
        if(tar < nums[0]) return false;
        
        int[] sides = new int[4];
        for(int i = 0; i < 4; i++) sides[i] = 0;
        return dfs(nums, sides, 0, tar);
        
    }
    
    private bool dfs(int[] nums, int[] sides, int idx, int tar){
        if(idx == nums.Length){
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        for(int i = 0; i < 4; i++){
            if(nums[idx] + sides[i] > tar) continue;
            
            int j = i;
            while(--j >= 0){
                if(sides[j] == sides[i]) break;
            }
            if(j != -1) continue;
            
            sides[i] += nums[idx];
            if(dfs(nums, sides, idx+1, tar)) return true;
            sides[i] -= nums[idx];
        }
        return false;
    }
}