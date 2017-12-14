/* 464. Can I Win
 * The core idea is letting players taking turns to pick number
 * And memorize the status of picked number (using int key)
 * detailed comment along the code
 */
 
public class Solution {
    // m[i] = 0: not calculated
    // m[i] = -1: current player lose
    // m[i] = 1; current player win
    int[] m = new int[1<<20];
    
    public bool CanIWin(int maxChoosableInteger, int desiredTotal) {
        int m = maxChoosableInteger, tar = desiredTotal;
        
        int sum = m*(m+1)/2;
        if(sum == tar) return m%2 == 1? true: false;
        return sum < tar? false: tar < 2? true: dfs(m, tar, 0);
    }
    
    bool dfs(int mx, int tar, int k){
        // if tar has been reached, current player lost
        // if not reached but m[k] = -1, then current player lost
        // if not reched and m[k] = 1, then current player win
        if(tar <= 0 || m[k] != 0) return tar>0 && m[k]>0;
        
        // pick number
        for(int i = 0; i < mx; ++i){
            // note here, << has higher priority than & or |
            // tar - i - 1 because 1<<i represents number: i+1
            if((k&1<<i) == 0 && !dfs(mx, tar - i - 1, k|1<<i)){
                m[k] = 1; // current player wins
                return true;    
            }
        }
        m[k] = -1;
        return false;
    }
}