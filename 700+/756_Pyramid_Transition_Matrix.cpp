/* 756. Pyramid Transition Matrix
 * Checking each pyramid line from bottom and pick out potential candidates of next
 * line above. Repeat this until reaching the top of pyramid. Detailed explanation please
 * see comments
 */

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> allowst(allowed.begin(), allowed.end());
        return helper(bottom, allowst);
    }
    
    bool helper(string bottom, unordered_set<string>& allowed){
        if(bottom.size() <= 1) return true;
        vector<string> cands(1, "");
        for(int i = 0; i < bottom.size()-1; i++){
            // candidate 'char'
            vector<string> tmp;
            for(char j = 'A'; j < 'Z'; j = static_cast<char>(j+1)){
                if(allowed.find(bottom.substr(i, 2).append(1, j)) != allowed.end()){
                    tmp.emplace_back(1, j);
                }
            }
            // if no candidate char then return
            if(tmp.size() == 0) return false;
            // candidate 'string'
            vector<string> tmp2;
            for(int j = 0; j < cands.size(); j++){
                for(int k = 0; k < tmp.size(); k++){
                    tmp2.push_back(cands[j] + tmp[k]);
                }
            }
            // move tmp2 to cands
            swap(cands, tmp2);
        }
        // if any of next recursion returns true. then return true
        for(string s: cands){
            if(helper(s, allowed)) return true;
        }
        return false;
    }
};