/*
 * You have 4 cards each containing a number from 1 to 9. You need to judge whether 
 * they could operated through *, /, +, -, (, ) to get the value of 24.
 */

public class Solution {
    private bool result = false;
    private double diff = 0.001;
    
    public bool JudgePoint24(int[] nums) {
        List<double> numList = new List<double>();
        foreach(int i in nums) numList.Add((double)i);
        Point24Helper(numList);
        return result;
    }
    
    private void Point24Helper(IList<double> nums){
        if(result) return;
        if(nums.Count == 1){
            if(Math.Abs(nums[0] - 24.0) < diff) result = true;
            return;
        }
        
        for(int i = 1; i < nums.Count; ++i){
            for(int j = 0; j < i; ++j){
                var newList = new List<double>();
                double p1 = nums[i], p2 = nums[j];
                newList.Add(p1+p2);
                newList.Add(p1-p2);
                newList.Add(p2-p1);
                newList.Add(p1*p2);
                if(Math.Abs(p1) > diff) newList.Add(p2/p1);
                if(Math.Abs(p2) > diff) newList.Add(p1/p2);
                
                nums.RemoveAt(i);
                nums.RemoveAt(j);
                foreach(double d in newList){
                    nums.Add(d);
                    Point24Helper(nums);
                    nums.RemoveAt(nums.Count-1);
                }
                nums.insert(j, p2);
                nums.insert(i, p1);
            }
        }
    }
}