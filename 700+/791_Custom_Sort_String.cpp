/* 791. Custom Sort String
 * The problem only asks us to return one of the valid sort string.
 * So we just need to form up a new string according to the order
 * Firstly, save all characters of frequencies into a hashmap
 * Then iterating through S, if character S[i] is in the map
 * we append number of mp[S[i]]'s S[i] to final result string and erase it
 * And in the end there may have some characrers left in map/
 * simplay append all left characters to the tail
 */

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> mp;
        for(char c: T){
            mp[c]++;
        }
        
        string res("");
        for(char c: S){
            auto it = mp.find(c);
            if(it != mp.end()){
                res = res + string(mp[c], c);
                mp.erase(it);
            }
        }
        
        for(auto& p: mp){
            res = res + string(p.second, p.first);
        }
        return res;
    }
};