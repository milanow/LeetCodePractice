/* 632. Smallest Range
 * Put all iterators of arrays in a priority queue, sorted by their first values,
 * where is begin() iterator points. Fisrtly assigning our result by calculating the max and min
 * in these first values and continuely updating the result as iteration.
 * In each iteration, pop out an iterator from priority queue and check it's next element
 * to see if it can update the result.
 */

class Solution {
    typedef vector<int>::iterator vit;
    
    struct Comp{
        bool operator()(const pair<vit, vit>& a, const pair<vit, vit>& b){
            return *a.first > *b.first;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<vit, vit>, vector<pair<vit, vit>>, Comp> pq;
        
        for(auto& p: nums){
            lo = min(lo, p[0]);
            hi = max(hi, p[0]);
            pq.emplace(p.begin(), p.end());
        }
        
        vector<int> res = {lo, hi};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if(p.first == p.second){
                break;
            }
            pq.push(p);
            
            lo = *pq.top().first;
            hi = max(*p.first, hi);
            if(hi - lo < res[1] - res[0]){
                res[0] = lo;
                res[1] = hi;
            }
            
        }
        return res;
    }
};