/* 554. Brick Wall
 * the idea is using a hashmap to record all edges for each row
 * Obviously to cross least bricks, we need to pass through edges as much as possible
 * A hashmap to record all possible edges to see at which point we can cross the most
 * edges
 */

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        int mn = len;
        
        unordered_map<int, int> mp;
        for(auto& row: wall){
            for(int i = 0, width = 0; i < row.size()-1; i++){
                mn = min(mn, len - ++mp[width += row[i]]);
            }
        }
        return mn;
    }
};