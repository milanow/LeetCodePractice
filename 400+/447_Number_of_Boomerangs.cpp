/* 447. Number of Boomerangs
 * for each point: p in points, p poses as 'i', when encountered one extra same distance
 * point, we could have 2*currentPointsWithSameDistance extra boomerangs because it can
 * be either 'j' or 'k'.
 */

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto &p : points) {
            unordered_map<int, int> ctr(points.size());
            for (auto &q : points)
                res += 2 * ctr[sqrDist(p, q)]++;
        }
        return res;
    }
    
    int sqrDist(pair<int, int>& p1, pair<int, int>& p2){
        return (p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second); 
    }
};