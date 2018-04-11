
/* 804. Unique Morse Code Words
 * The solution is straight-forward, just translate/encode the words inside array into
 * Morse number/string and to check how many possible strings could have.
 */

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> st;
        for(int i = 0; i < words.size(); i++){
            string str;
            for(int j = 0; j < words[i].size(); j++){
                str += dict[words[i][j] - 'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};