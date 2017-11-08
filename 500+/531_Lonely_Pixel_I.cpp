/* 531. Lonely Pixel I
 * Check through each cells to see which meets the requirement
 */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if(!m) return 0;
        int n = picture[0].size();
        if(!n) return 0;
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) res++;
            }
        }
        
        return res;
    }
};