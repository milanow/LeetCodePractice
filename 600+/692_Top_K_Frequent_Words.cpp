/* 692. Top K Frequent Words
 * Using priority queue to "sort" the original words by comparing the frequency
 * and alphabetical order. Then pick up the top k's words and save it into the results
 */

class Solution {
    struct Comp{
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2){
            return p1.second < p2.second || p1.second == p2.second && p1.first > p2.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto& w: words){
            mp[w]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> pq(mp.begin(), mp.end());
        vector<string> res;
        while(!pq.empty() && k > 0){
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};