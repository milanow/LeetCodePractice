/* 498. Diagonal Traverse
 * no need to consider the edge cases when index is out of range
 * just save all diagonal array and reverse the odd diagonal and save it to final result
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return vector<int>();
        int n = matrix[0].size();
        if(!n) return vector<int>();
    
        vector<vector<int>> dignals(m+n-1);
        for(int i = 0; i < m+n-1; i++){
            int row = max(0, i-n+1);
            int col = min(i, n-1);
            for(; row < m && col >= 0; row++, col--){
                dignals[i].push_back(matrix[row][col]);
            }
        }
        vector<int> res;
        for(int i = 0; i < m+n-1; i++){
            if(i%2) res.insert(res.end(), dignals[i].begin(), dignals[i].end());
            else res.insert(res.end(), dignals[i].rbegin(), dignals[i].rend());
        }
        return res;
    }
};