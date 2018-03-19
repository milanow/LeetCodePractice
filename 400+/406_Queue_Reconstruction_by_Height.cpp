/* 406. Queue Reconstruction by Height
 * We only need to keep save heights' people's relative order being correct
 * And the next thing is to insert them into a queue where higher people being
 * inserted first because you dont need to care higher people's positions when
 * inserting lower people.
 */

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
        };
        
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        for(auto& p: people){
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};