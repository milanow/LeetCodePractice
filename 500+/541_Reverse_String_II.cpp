/* 541. Reverse String II
 * Find out all start index of "reverse point"
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        
        vector<int> tarindex;
        for(int i = 0; i < len; i += 2*k){
            tarindex.push_back(i);
        }
        for(auto i: tarindex){
            reverse(s.begin()+i, s.begin()+((i+k) > len? len: (i+k)));
        }
        return s;
    }
};