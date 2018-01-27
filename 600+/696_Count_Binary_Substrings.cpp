/* 696. Count Binary Substrings
 * Encoding original string by counting each block of 0's and 1's
 * and save the number into an array.
 * the substrings who's number of 1 and 0 equals are 1..10...0 or
 * 0...01...1, thus for two adjcent 0 and 1 blocks
 * the smaller number of block is the number of substrings that 
 * they can generate.
 * e.g. encoding(1110000) = {3, 4}
 * there are 3 substrings containing 1, 2 or 3 1's: 10, 1100, 111000
 */ 

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> vecs;
        int cnt = 1;
        for(int i = 1; i <= s.size(); i++){
            if(i < s.size() && s[i] == s[i-1]){
                cnt++;
            }else{
                vecs.push_back(cnt);
                cnt = 1;
            }
        }
        
        int res = 0;
        // if(vecs.size() < 2) return res;
        for(int i = 1; i < vecs.size(); i++){
            res += min(vecs[i], vecs[i-1]);
        }
        return res;
    }
};