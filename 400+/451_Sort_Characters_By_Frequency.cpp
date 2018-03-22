/* 451. Sort Characters By Frequency
 * Sorting the characters according to its frequency using STL sort
 */

class Solution {

public:
    string frequencySort(string s) {
        int dict[256] = {0};
        for(char c: s){
            dict[c]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) { 
            return dict[a] > dict[b] || (dict[a] == dict[b] && a < b); 
        }); 
        return s;
    }
};