/* 715. Range Module
 * Obviously, to save number ranges, pair<int, int> is always the first choice
 * Secondly we need a sorted order to insert/remove range intervals
 * To conclude, map<int, int> can be perfect. 
 * When add a new range, we first check all possible intervals that may have
 * intersection with target range interval and reset our intervals. Same for
 * removing a range. When query a range, we just need to find out if there is
 * a continuous interval that our query range is a subset of it.
 */

class RangeModule {
    map<int, int> intervals;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if(l != intervals.begin()){
            l--;
            if(l->second < left) l++;
        }
        if(l != r){
            left = min(l->first, left);
            right = max(right, (--r)->second);
            intervals.erase(l, ++r);
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if(it == intervals.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if(l != intervals.begin()){
            l--;
            if(l->second <= left) l++;
        }
        if(l == r) return;
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        intervals.erase(l, ++r);
        if(l1 < left) intervals[l1] = left;
        if(r1 > right) intervals[right] = r1;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */