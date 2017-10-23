/* 624. Maximum Distance in Arrays
 * *comment out's solution is mine...obviously too naive. 
 * Update the answer first then update left and right, in such way, we can avoid the situation
 * that leftmost & rightmost come from same array.
 */

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left = arrays[0][0], right = arrays[0].back(), ans = 0;
        for(int i = 1; i < arrays.size(); ++i){
            ans = max(ans, max(abs(left - arrays[i].back()), abs(right - arrays[i][0])));
            left = min(left, arrays[i][0]);
            right = max(right, arrays[i].back());
        }
        return ans;
//         int m = arrays.size();
//         int mn1 = INT_MAX, mn2 = INT_MAX, mx1 = INT_MIN, mx2 = INT_MIN;
//         int mn1idx = -1, mn2idx = -1, mx1idx = -1, mx2idx = -1;
        
//         for(int i = 0; i < m; ++i){
//             if(arrays[i][0] < mn1){
//                 mn2 = mn1;
//                 mn2idx = mn1idx;
//                 mn1 = arrays[i][0];
//                 mn1idx = i;
//             }else if(arrays[i][0] < mn2){
//                 mn2 = arrays[i][0];
//                 mn2idx = i;
//             }
            
//             if(arrays[i].back() > mx1){
//                 mx2 = mx1;
//                 mx2idx = mx1idx;
//                 mx1 = arrays[i].back();
//                 mx1idx = i;
//             }else if(arrays[i].back() > mx2){
//                 mx2 = arrays[i].back();
//                 mx2idx = i;
//             }
//         }
        
//         if(mx1idx != mn1idx) return mx1 - mn1;
//         else return max(mx1 - mn2, mx2 - mn1);
    }
};