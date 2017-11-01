/* 567. Permutation in String
 * Sliding window problem, the key is to keep track on character distribution of substring of s2
 * If at any point, the distribution of s1 and s2.substr is same (with all elements in dict equal zero),
 * then this "window" is a permutaion of s1
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if(len1 > len2) return false;
        
        vector<int> dict(26, 0);
        for(int i = 0; i < len1; i++){
            dict[s1[i] - 'a']++;
        }
        
        string key("");
        for(int i = 0; i < 26; ++i){
            if(dict[i] > 0) key += to_string((char)('a' + i)) + to_string(dict[i]); 
        }
        
        for(int i = 0; i < len2; ++i){
            if(i >= len1) dict[s2[i-len1] - 'a']++;
            dict[s2[i]-'a']--;
            
            int j = 0;
            for(j = 0; j < 26; j++){
                if(dict[j] != 0) break;
            }
            if(j == 26) return true;
        }
        return false;
    }
};