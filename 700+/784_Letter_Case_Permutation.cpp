/* 784. Letter Case Permutation
 * Just fill up the answers according to the demand
 */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res(1, "");
        for(int i = 0; i < S.length(); i++){
            if(isdigit(S[i])){
                for(int j = 0; j < res.size(); j++){
                    res[j].append(1, S[i]);
                }
            }
            else{
                vector<string> tmp;
                for(int j = 0; j < res.size(); j++){
                    tmp.push_back(res[j] + static_cast<char>(toupper(S[i])));
                    tmp.push_back(res[j] + static_cast<char>(tolower(S[i])));
                }
                swap(tmp, res);
            }
        }
        return res;
    }
};