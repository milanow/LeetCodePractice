/* 469. Convex Polygon
 * the input points are joined sequentially, so we just need to check along anti-clockwise
 * order to see if adjacent sides 'rotating' to the same direction.
 * using cross product to see if they are all positive or negative
 */

public class Solution {
    // public class PointsComp: IComparer<List<int>>
    // {
    //     public int Compare(List<int> p1, List<int> p2)
    //     {
    //         if(p1[0] < p2[0] || p1[0] == p2[0] && p1[1] < p2[1]) return -1;
    //         else return 1;
    //     }
    // }
    
    public bool IsConvex(IList<IList<int>> points) {
        // No need to sort first because the points are joined sequentially       
        int n = points.Count;
        if(n < 3) return false;
        int i = 0;
        for(long pre = 0, cur; i < n; ++i){
            cur = cross(points, i, (i+1)%n, (i+2)%n);
            if(cur != 0){
                if(cur*pre < 0) return false;
                pre = cur;
            }
        }
        return true;
    }
    
    // x1*y2 - x2*y1, 2D cross product
    public long cross(IList<IList<int>> points, int p1, int p2, int p3){
        return (points[p2][0] - points[p1][0])*(points[p3][1] - points[p2][1]) - (points[p3][0] - points[p2][0])*(points[p2][1]-points[p1][1]);
    }
    
}