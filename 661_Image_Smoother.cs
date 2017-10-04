/* 661. Image Smoother
 * Idea is straightforward, for every cell, calculates its new value after smoothing.
 * But to use O(1) space, use the other bits exceot the lowest 8 bits as new value,
 * Since the grey int value has a range from 0 - 255 (8 bits)
 */
public class Solution {
    public int[,] ImageSmoother(int[,] M) {
        int m = M.GetLength(0);
        int n = M.GetLength(1);
        if(m == 0 || n == 0) return new int[0,0];
    
        int[,] dirs = {{-1, 0}, {1, 0}, {-1, 1}, {-1,-1}, {1,-1}, {1, 1}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int sum = M[i,j], cnt = 1;
                for(int k = 0; k < 8; ++k){
                    int x = i + dirs[k,0];
                    int y = j + dirs[k,1];
                    if(x < 0 || x > m-1 || y < 0 || y > n-1) continue;
                    sum += (M[x,y] & 0xFF);
                    cnt += 1;
                }
                M[i,j] |= ((sum / cnt) << 8);
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                M[i,j] >>= 8;
            }
        }
        return M;
    }
}