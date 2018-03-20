/* 422. Valid Word Square
 * Checking mirror position is easy, the trick part is to find out what if one of
 * two mirror positions doesn't exist (string is not long enough).
 */

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(i >= words[j].size() || j >= words.size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};