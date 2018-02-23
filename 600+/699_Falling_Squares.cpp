/* 699. Falling Squares
 * The basic idea to tackle this problem is storing heights of each positions
 * of current infinite number line (well it ranges from 1 to 10^8+10^6 according to Notes)
 * We store these heights by saving line segments [i, j) with height h into a sorted map
 * which has type of map<pair<int, int>, int> storing i, j and h.
 * 
 * Then iterating through the dropping squares and keep track of current heighest height.
 * In each iteration, we found all line segments that intercross with the square
 * and update our map by break up these line segments(because new square may change height)
 * and assigning them appropriate height.
 * 
 * Then comparing the new height with maxheight and store the value into result array.
 */ 

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        map<pair<int, int>, int> mp;
        mp[make_pair(0, 1000000000)] = 0;
        vector<int> res;
        int mx = 0;
        for(auto& p: positions){
            int len = p.second, a = p.first, b = p.first + p.second, h = 0;
            vector<vector<int>> tmp;
            // find the first segment whose begin/first is smaller than a
            auto it = mp.upper_bound({a, a});
            if(it != mp.begin() && (--it)->first.second == a) it++;
            
            while(it != mp.end() && it->first.first < b){
                if(a > it->first.first) tmp.push_back({it->first.first, a, it->second});
                if(b < it->first.second) tmp.push_back({b, it->first.second, it->second});
                h = max(h, it->second);
                it = mp.erase(it);
            }
            mp[{a, b}] = h + len;
            for(auto& v: tmp) mp[{v[0], v[1]}] = v[2];
            mx = max(h+len, mx);
            res.push_back(mx);
        }
        return res;
    }
};