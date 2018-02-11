/* 748. Shortest Completing Word
 * Save each string to a dictionary, which is a int[26] array representing the frequency of
 * 26 characters in a string. Comparing each words in words array and to see if it contains
 * all needed characters of licensePlate
 */

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> lp(26, 0);
        for(int i = 0; i < licensePlate.length(); i++){
            if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z') lp[licensePlate[i] - 'a']++;
            else if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') lp[licensePlate[i] - 'A']++;
        }
        
        string cand = "";
        for(int i = 0; i < words.size(); i++){
            vector<int> tmp(26, 0);
            int j;
            for(j = 0; j < words[i].size(); j++){
                tmp[words[i][j] - 'a']++;
            }
            for(j = 0; j < 26; j++){
                if(tmp[j] < lp[j]) break;
            }
            if(j == 26){
                // found candidate
                if(cand == "" || cand.length() > words[i].length()){
                    cand = words[i];
                }
            }
        }
        return cand;
    }
};