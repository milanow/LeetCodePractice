/* 575. Distribute Candies
 * This question is actully asking how many kinds of candies in total and if the 
 * sister can get all kinds of candies.
 * Happee Halloween - 10/31/2017
 */

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int tar = candies.size() / 2;
        unordered_set<int> st;
        for(int i: candies){
            st.insert(i);
        }
        
        return min(tar, static_cast<int>(st.size()));
    }
};