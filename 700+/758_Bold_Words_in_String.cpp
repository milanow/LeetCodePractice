/* 758. Bold Words in String
 * The solution can be broken down to 3 pieces
 * 1. Find out and mark all words inside S as pair<startindex, endindex>()
 * 2. merge these indexes to save bold mark because some words need bolding 
 *    may overlap
 * 3. insert bold tags from back
 */

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<pair<int, int>> pairs;
        convertToPairs(words, pairs, S);
        vector<pair<int, int>> mergedPairs;
        mergeInterval(pairs, mergedPairs);
        for(auto it = mergedPairs.rbegin(); it != mergedPairs.rend(); it++){
            S.insert(it->second, "</b>");
            S.insert(it->first, "<b>");
        }
        return S;
    }
    
private:
    void convertToPairs(vector<string>& words, vector<pair<int, int>>& pairs, string s){
        for(string& str: words){
            int n = str.size();
            for(int i = 0; (i = s.find(str, i)) != string::npos; ++i){
                pairs.push_back(pair<int, int>(i, n+i));
            }
        }
    }
    
    void mergeInterval(vector<pair<int, int>>& src, vector<pair<int, int>>& dest){
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;  
        };
        sort(src.begin(), src.end(), comp);
        
        for(int i = 0, j = -1; i < src.size(); i++){
            if(j < 0 || dest[j].second < src[i].first){
                dest.push_back(src[i]);
                j++;
            }else{
                dest[j].second = max(dest[j].second, src[i].second);
            }
        }
    }
};