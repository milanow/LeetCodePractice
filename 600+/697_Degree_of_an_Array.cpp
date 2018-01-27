/* 697. Degree of an Array
 * The shortest subarray must contain all copies of number who represents the degree
 * of original array. Thus we must achieve the goal of 
 * 1) head and tail of the subarray is that number represents degree, because if there 
 *    was another number be head or tail, it can be shortened
 * 2) there might be multiple number represents the degree of original array
 *    (e.g. {1,3,2,3,1}, 1 and 3 can both represents the degree number)
 *    however, to have all 1 included, the subsarray has to be: 1,3,2,3,1
 *    for 3, we just need 3,2,3, which is shorter
 *
 * So the algorithm first collect information about which number can represents the degree
 * or original array and save their indexes. Secondly, iterating through all these number
 * to see the length of their subarray that can be same degree of original array.
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int mx = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
            mx = max(mx, static_cast<int>(mp[nums[i]].size()));
        }
        if(mx == 1) return 1;
        
        int mn = nums.size();
        for(auto& p: mp){
            if(p.second.size() == mx){
                mn = min(mn, p.second.back() - p.second.front());
            }
        }
        return mn+1;
    }
};