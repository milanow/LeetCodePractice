/* 436. Find Right Interval
 * The solution is quite straight-forward. Simply saving all starts of intervals in
 * a sorted map and binding them with the index
 * The reast thing is using built-in lower_bound methods to find out the min start that
 * larger or equal to the interval's end. It is actually a binary search process
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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        for(int i = 0; i < intervals.size(); i++){
            mp[intervals[i].start] = i;
        }
        
        vector<int> res;
        for(auto interval: intervals){
            auto it = mp.lower_bound(interval.end);
            if(it == mp.end()) res.push_back(-1);
            else res.push_back(it->second);
        }
        return res;
    }
};