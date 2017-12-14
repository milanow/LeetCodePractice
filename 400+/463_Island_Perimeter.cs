/* 463. Island Perimeter
 * 1 pair of adjcent island have 2 redundant sides
 * minus redundant sides to calculate perimeter
 */
 
public class Solution {
    public int IslandPerimeter(int[,] grid) {
        int m = grid.GetLength(0);
        if(m == 0) return 0;
        int n = grid.GetLength(1);
        if(n == 0) return 0;
        
        int p = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i,j] == 1){
                    p += 4;
                    if(i > 0 && grid[i-1,j] == 1) p -= 2;
                    if(j > 0 && grid[i,j-1] == 1) p -= 2;
                }
            }
        }
        return p;
    }
}