/* 767. Reorganize String
 * First we need to record the frequency of each characters in the string S
 * And sort it in the order of "the largest frequency comes first" in a priority_queue
 * if (S.size()+1) / 2 < maxfrequency, it means the string is not long enough to have 
 * such high frequency character(the corner case might be: abababaa, there (8+1)/2 < 5)
 * Secondly, we need to insert characters from higher frequency, but we have a queue
 * to serve as a temporary terminator to avoid one character being inserted twice without
 * other characters between.
 */ 

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.length();
        if(n == 1) return S;
        
        unordered_map<char, int> mp;
        for(char c: S){
            mp[c]++;
        }
        auto comp = [](const pair<char, int>& p1, const pair<char, int>& p2){
            return p1.second < p2.second;  
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(mp.begin(), mp.end(), comp);
        int mxfreq = pq.top().second;
        
        if((n+1) / 2 < mxfreq) return "";
        if(mxfreq == 1) return S;
        
        // myq is used to depart the same character
        queue<pair<char, int>> myq;
        string ans;
        while(!pq.empty() || myq.size() > 1){
            if(myq.size() > 1){
                auto p = myq.front();
                myq.pop();
                if(p.second != 0) pq.push(p);
            }
            if(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                ans += p.first;
                p.second--;
                myq.push(p);
            }
        }
        return ans;
    }
};