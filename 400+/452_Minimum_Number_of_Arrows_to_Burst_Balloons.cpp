/* 452. Minimum Number of Arrows to Burst Balloons
 * Greedy algorithm, since for a balloon, it doesn't matter which arrow to shoot it.
 * So we could use one arrow to shoot balloons as many as possible
 * For a single arrow, we can choose a range representing where the arrow can be shooted
 * With checking more and more balloon, the range becomes smaller. When it becomes 
 * impossible for using one arrow to shoot one extra balloon (e.g. range [1, 2] and balloon [4, 5])
 * we need a new arrow.
 * Sorting balloons first is to making sure used arrow cannot be reused.
 */

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;
        };
        
        sort(points.begin(), points.end(), comp);
        if(points.size() == 0) return 0;
        
        int res = 1;
        int start = points[0].first, end = points[0].second;
        for(int i = 1; i < points.size(); i++){
            // need a new arrow
            if(points[i].first > end){
                res++;
                start = points[i].first;
                end = points[i].second;
            }else{
                start = points[i].first;
                end = min(end, points[i].second);
            }
        }
        return res;
    }
};