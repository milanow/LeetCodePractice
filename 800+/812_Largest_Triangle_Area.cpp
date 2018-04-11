/* 812. Largest Triangle Area
 * The triangle area can be calculated by cross product of two vector, 
 * except that this time we only need the module
 */

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        // area = 0.5 * abs(AB X AC)
        // AB X AC = (xb - xa, yb - ya) X (xc - xa, yc - ya)
        //         = (xb - xa)(yc - ya) - (yb - ya)(xc - xa)
        
        for(auto& p1: points){
            for(auto& p2: points){
                for(auto& p3: points){
                    res = max(res, 0.5 * abs(p2[0]*p3[1] - p1[0]*p3[1] - p2[0]*p1[1] - p2[1]*p3[0] + p2[1]*p1[0] + p1[1]*p3[0]));
                }
            }
        }
        return res;
    }
};