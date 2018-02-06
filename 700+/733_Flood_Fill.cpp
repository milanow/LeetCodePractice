/* 733. Flood Fill
 * A typical dfs problem. Replace each adjacent cells by newColor via DFS.
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0 || sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return image;
        if(image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor){
        image[x][y] = newColor;
        
        if(x > 0 && image[x-1][y] == color) dfs(image, x-1, y, color, newColor);
        if(x < image.size()-1 && image[x+1][y] == color) dfs(image, x+1, y, color, newColor);
        if(y > 0 && image[x][y-1] == color) dfs(image, x, y-1, color, newColor);
        if(y < image[0].size()-1 && image[x][y+1] == color) dfs(image, x, y+1, color, newColor);
        
    }
};