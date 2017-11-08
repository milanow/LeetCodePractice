/* 524. Longest Word in Dictionary through Deleting
 * No magic at all, just accomplish the requirement step by step
 * 1. sort the dict by order where longer string comes first
 * 2. check string in dict from longest string first until we find candidates
 *    that shorter than other candidates. A candidate string can be subsequence string
 *    of original string.
 * 3. Among all candidates, we find out a candidate with small lexicographical order.
 */

class Solution {
    bool isS1subofS2(const string& s1, const string s2){
        int i = 0, j = 0;
        for(;i < s1.length();i++){
            while(j < s2.length() && s1[i] != s2[j]) j++;
            if(j == s2.length()) return false;
            j++;
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        auto lenComp = [](const string& l, const string& r){
            return l.length() > r.length();
        };
        
        sort(begin(d), end(d), lenComp);
        int sz = 0;
        vector<string> cand;
        for(int i = 0; i < d.size(); ++i){
            if(d[i].length() >= sz && isS1subofS2(d[i], s)){
                sz = d[i].length();
                cand.push_back(d[i]);
            }else if(d[i].length() < sz) break;
        }
        
        if(cand.size() == 0) return "";
        if(cand.size() == 1) return cand[0];
        partial_sort(begin(cand), begin(cand)+1, end(cand));
        return cand[0];
    }
};