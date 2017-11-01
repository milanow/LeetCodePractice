/* 587. Erect the Fence
 * The question is actually to find out a convex hull
 * My original idea is find out the lowest point first (min point.y) and continually
 * find next point by calculating the slope of line of the previous point and next point
 * But it is way more complicated from big-O time complexity.
 * 
 * This solution is using 2D vector cross product to determine which line is "above" or say
 * larger angel. Because cross product is not commutative, the value may become negative with
 * commutation (normal vector inversed). This property can be used to determine which angel is 
 * larger. 
 * Firstly sorting the points by x value. Then inserting and updating the selected points
 * And deleting duplicate points (because this is not drawing a convex hull, but selecting points)
 * The finaly answer is there.
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    long long cross(Point& o, Point& a, Point& b){
        return (a.x - o.x) * (long long)(b.y - o.y) - (a.y - o.y) * (long long)(b.x - o.x);
    }
    
    static bool equ(Point& p1, Point& p2) { return p1.x == p2.x && p1.y == p2.y; }
public:
    vector<Point> outerTrees(vector<Point>& points) {
        auto comp = [](const Point& p1, const Point& p2){
            return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
        };
        
        sort(points.begin(), points.end(), comp);
        
        int n = points.size();
        vector<Point> hull(2 * n);
        
        int k = 0;
        // lower convex hull
        for(int i = 0; i < n; ++i){
            while(k >= 2 && cross(hull[k-2], hull[k-1], points[i]) < 0) k--;
            hull[k++] = points[i];
        }
        
        // upper convex hull
        for(int i = n - 2, t = k + 1; i >= 0; --i){
            while(k >= t && cross(hull[k-2], hull[k-1], points[i]) < 0) k--;
            hull[k++] = points[i];
        }
        
        hull.resize(k);
        sort(hull.begin(), hull.end(), comp);
        hull.erase(unique(hull.begin(), hull.end(), equ), hull.end());
        return hull;
        
    }

};