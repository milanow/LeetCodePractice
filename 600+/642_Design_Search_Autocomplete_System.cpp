/* 642. Design Search Autocomplete System
 * record the whole diction as a hashmap, for each inputs, set a priority queue for finding
 * best candidate as result
 */

class AutocompleteSystem {
    unordered_map<string, int> dict;
    string curstr;
    
    
public:
    // struct Comp{
    // public:
    //     bool operator()(const pair<string, int>& p1, const pair<string, int>& p2){
    //         return p1.second > p2.second || p1.second == p2.second && p1.first < p2.first;  
    //     }
    // };
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for(int i = 0; i < times.size(); ++i){
            dict[sentences[i]] += times[i];
        }
        curstr.clear();
    }
    
    vector<string> input(char c) {
        if(c == '#'){
            dict[curstr]++;
            curstr.clear();
            return vector<string>();
        }
        
        curstr.push_back(c);
        // Reserve the best, that's why uses "greater"
        auto Comp = [](const pair<string, int>& p1, const pair<string, int>& p2){
            return p1.second > p2.second || p1.second == p2.second && p1.first < p2.first;  
        };
        
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(Comp)> pq(Comp);
        for(auto& p: dict){
            bool match = true;
            for(auto i = 0; i < curstr.size(); ++i){
                if(i >= p.first.size() || curstr[i] != p.first[i]){
                    match = false;
                    break;
                }
            }
            
            if(match){
                pq.push(p);
                if(pq.size() > 3){
                    pq.pop();
                }
            }
        }
        
        vector<string> res(pq.size());
        for(int i = pq.size()-1; i >= 0; --i){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */