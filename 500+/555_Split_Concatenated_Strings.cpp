/* 555. Split Concatenated Strings
 * The problem can be splitted to two parts, firstly, for sure, only at most one string
 * in strs can be "cut". But despite of this special string, the other stirngs must be 
 * in lexicographically biggest order.
 * Having know the truth, we first construct a string links strs together, where each strs[i]
 * have the biggest lexicographically order by reverse or not.
 * Secondly, we check each string and try to cut it at some point. 
 * "body" represents the other strings linked together, to find the best answer,
 * we need to compare all of them by adding different "head" and "tail" to the "body"
 */

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s = "", res = "a";
        for(auto i = 0; i < strs.size(); i++){
            auto r = strs[i];
            reverse(r.begin(), r.end());
            s += max(r, strs[i]);
        }
        
        for(auto i = 0, spos = 0; i < strs.size(); spos += strs[i++].size()){
            string p1 = strs[i], p2 = strs[i], body = s.substr(spos + p1.size()) + s.substr(0, spos);
            reverse(p2.begin(), p2.end());
            for(auto j = 0; j < strs[i].size(); j++){
                if(p1[j] >= res[0]) res = max(res, p1.substr(j) + body + p1.substr(0, j));
                if(p2[j] >= res[0]) res = max(res, p2.substr(j) + body + p2.substr(0, j));
            }
        }
        return res;
    }
};