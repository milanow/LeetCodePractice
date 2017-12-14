/* 475. Heaters
 * First we sort the heaters and house array
 * Then we check each house positions. In each iteration, we find two heaters (if possible)
 * which one of heater's position is smaller than house, the other one is larger than house
 * And find the smaller distance the house need to be heated. Updating the distance by chossing the
 * max of current distance and minDist of two heaters.
 * Keep the process and find the min distance the heaters need to cover and heat all houses
 */

public class Solution {
    public int FindRadius(int[] houses, int[] heaters) {
        int res = 0, prev = 0;
        
        Array.Sort(houses);
        Array.Sort(heaters);
        
        for(int i = 0; i < houses.Length; i++){
            int j;
            for(j = prev; j < heaters.Length; j++){
                if(heaters[j] >= houses[i]) break;
            }
            
            int mindist = Int32.MaxValue;
            if(j != heaters.Length){
                mindist = heaters[j] - houses[i];
            }
            
            if(j != 0){
                mindist = Math.Min(mindist, houses[i] - heaters[j-1]);
            }
            
            res = Math.Max(res, mindist);
            prev = j;
        }
        return res;
    }
}