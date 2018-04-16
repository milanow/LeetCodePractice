/* 816. Ambiguous Coordinates
 * There are many corner cases for this question, but still, we could observe that:
 * 1. there must be a comma, so we divide original string into two substr
 * 2. for each substr,
 *      1) if it has a leading zero and tailing zero, then all numbers formed by this substr is invalid
 *      2) else if we have a leading zero, then this substr could only form number like: 0.xxxxx
 *      3) else if we have a tailing zero, then this substr cannot have a decimal point
 *      4) else we can divide the substr into integer part and decimal part
 * Then pushing all valid possibilities into the answer
 */

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        // Comma is a must, so we divided original strings into two numbers
        vector<string> res;
        // eliminate bracket
        int len = S.length();
        S = S.substr(1, len-2);
        for(int i = 1; i <= len-3; i++){
            vector<string> strs1, strs2;
            processNum(S.substr(0, i), strs1);
            processNum(S.substr(i), strs2);
            for(string& str1: strs1){
                for(string& str2: strs2){
                    res.emplace_back("(" + str1 + ", " + str2 + ")");
                }
            }
            
        }
        return res;
    }
    
    void processNum(string str, vector<string>& cands){
        // str is guarenteed not to be 0 lenth, but just in case I was wrong
        if(str.length() == 0) return;
        // No digital point
        if(str.length() == 1){
            cands.push_back(str);
            return;
        }
        int len = str.length();
        // leading zero is not permitted, tailing zero is not permitted, which may lead two parts divieded by 
        // digital point are zero
        if(str[0] != '0' && str[len-1] != '0'){
            cands.push_back(str);
            for(int i = 1; i < len; i++){
                // check where we could insert digital point;
                cands.push_back(str.substr(0, i) + "." + str.substr(i));
            }
        }else if(str[0] != '0'){
            cands.push_back(str);
        }else if(str[len-1] != '0'){
            cands.push_back("0." + str.substr(1));
        }
        
        
    }
};