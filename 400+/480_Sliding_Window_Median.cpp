/* 480. Sliding Window Median
 * Maintain a window, which is a sortedset, push the median into result and
 * dynamically maintain the window, also maintain the iterater of mid
 * if new inserting number is smaller then decrease the mid pointer
 * if removed element is equal or smaller then increase the mid pointer
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        // mid or be right to the mid when k is even
        auto mid = next(window.begin(), k/2);
        vector<double> res;
        for(int i = k; i < nums.size(); i++){
            res.push_back((static_cast<double>(*mid) + *prev(mid, 1-k%2)) / 2);
            
            window.insert(nums[i]);
            // if inserting into left of mid
            // Note the difference when self-decre or self-incre mid
            if(nums[i] < *mid) mid--;
            
            if(nums[i-k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
        res.push_back((static_cast<double>(*mid) + *prev(mid, 1-k%2)) / 2);
        return res;
    }
};