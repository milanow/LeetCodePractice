/* 522. Longest Uncommon Subsequence II
 * Longest Uncommon Subsequence I has showed that when finding longest uncommon
 * subsequence, the key is if two strings are equal. So to find out longest subsequence
 * among multiple strings, the first key is finding out 1)longest 2)unique string
 * Following this idea, we re-store the input, sort the string based on string length
 * Then we saerch from longest string to see if it is unique.
 * If it is unique, there is a chance that it can be subsequence of previous, searched
 * longer string. If it is a subsequence of previous string, we conitnue finding another
 * answer. If not, it is the answer.
 */

class Solution {
    bool isS1SubstrOfS2(string s1, string s2){
        int i = 0, j = 0;
        for(;i < s1.length() && j < s2.length(); i++, j++){
            while(j < s2.length() && s1[i] != s2[j]) j++;
            if(j == s2.length()) return false;
        }
        return i == s1.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        struct Comp{
            bool operator()(const pair<string, int>& l, const pair<string, int>& r) const{
                return l.first.length() > r.first.length();
            }  
        };
        
        unordered_map<string, int> mp;
        for(auto& str: strs){
            ++mp[str];
        }
        vector<pair<string, int>> pvec(mp.begin(), mp.end());
        sort(begin(pvec), end(pvec), Comp());
        
        for(int i = 0; i < pvec.size(); i++){
            if(pvec[i].second == 1){
                int j = 0;
                for(; j < i; j++){
                    if(isS1SubstrOfS2(pvec[i].first, pvec[j].first)) break;
                }
                if(i == j) return pvec[i].first.size();
            }
        }
        return -1;
    }
};