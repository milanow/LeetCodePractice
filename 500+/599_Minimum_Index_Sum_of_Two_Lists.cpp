/* 599. Minimum Index Sum of Two Lists
 * Save all the info into a map to let two lists "interact" with each other
 * if they have same resteraunt, when calculate the index sum
 * find out the min index sum and return the all restaurants have that much index sum
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < list1.size(); ++i){
            mp[list1[i]].push_back(i);
        }
        for(int i = 0; i < list2.size(); ++i){
            mp[list2[i]].push_back(i);
        }
        
        int minIdx = INT_MAX;
        for(auto p: mp){
            if(p.second.size() > 1){
                minIdx = min(minIdx, (p.second)[0] + (p.second)[1]);
            }
        }

        vector<string> res;
        for(auto p: mp){
            if(p.second.size() > 1 && (p.second)[0] + (p.second)[1] == minIdx){
                res.push_back(p.first);
            }
        }
        return res;
    }
};