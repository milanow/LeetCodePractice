/* 435. Non-overlapping Intervals
 * Firstly we need to sort the intervals by its starting position
 * Then, when we find two intervals overlapping together, we must delete on of them
 * but which one we should delete? The answer is the one with smaller end.
 * because with smaller end, it has fewer chances to overlap with upcomming larger intervals
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        };
        if(intervals.size() < 2) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        for(int i = 1, pre = 0; i < intervals.size(); i++){
            if(intervals[i].start < intervals[pre].end){
                res++;
                // i has smaller end
                if(intervals[i].end < intervals[pre].end) pre = i;
            }else{
                // no overlapping
                pre = i;
            }
        }
        return res;
    }
};