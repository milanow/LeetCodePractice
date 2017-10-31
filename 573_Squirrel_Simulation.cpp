/* 573. Squirrel Simulation
 * The distance in total consist two parts: path from nuts to tree & path from squirrel to one nut
 * The distance equals 2*sum(nuts to tree) - (one nut to tree) + (squirrel to same nut)
 * 2*sum(nuts to tree) is constant, thus we only need to find a nut such that
 * -(one nut to tree) + (squirrel to same nut) is min
 */

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        if(nuts.size() == 0) return 0;
        int mn = INT_MAX;
        int baseDist = 0;
        for(auto& nut: nuts){            
            int dist1 = abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]);
            int dist2 = abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
            
            baseDist += dist2;
            mn = min(mn, dist1 - dist2);
        }
        
        return baseDist*2 + mn;
    }
};