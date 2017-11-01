/* 638. Shopping Offers
 * The strategy is if possible, apply as many as special offer possible. Use a hashmap to record calculated situation
 * for each step, we check if current special offer can be used, if did, we take this offer to see if this is the min
 * money we can spend to reach the requirement.
 */

public class Solution {
    public int ShoppingOffers(IList<int> price, IList<IList<int>> special, IList<int> needs) {
        var dict = new Dictionary<int, int>();
        return Helper(price, special, dict, GetKey(needs));
    }
    
    private int Helper(IList<int> price, IList<IList<int>> spec, IDictionary<int, int> dict, int k){
        if(dict.ContainsKey(k)) return dict[k];
        
        int len = price.Count;
        if(len == 0) return -1;
        int[] pows = new int[len];
        
        pows[0] = 1;
        for(int i = 1; i < len; ++i){
            pows[i] = pows[i-1]*10;
        }
        
        int ans = 0, need = k;
        for(int i = 0; i < len; ++i){
            ans += price[i]*(need%10);
            need /= 10;
        }
        
        foreach(var sp in spec){
            int key = k, i = 0;
            while(i < len){
                int t = (key/pows[i])%10;
                if(sp[i] <= t){
                    key -= sp[i]*pows[i];
                }else{
                    break;
                }
                ++i;
            }
            if(i == len){
                ans = Math.Min(ans, sp[len] + Helper(price, spec, dict, key));
            }
        }
        
        dict.Add(k, ans);
        return ans;
    }
    
    private int GetKey(IList<int> needsK){
        int res = 0;
        for(int i = 0, pow = 1; i < needsK.Count; ++i, pow*=10){
            res += needsK[i]*pow;
        }
        return res;
    }
}