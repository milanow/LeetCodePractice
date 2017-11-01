/* 557. Reverse Words in a String III
 * Ah reverse is reverse....get single word by spliting array by ' ' and reverse single word
 * Making a new string to compose the final answer
 */

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string str, res;
        while(getline(iss, str, ' ')){
            res += string(str.rbegin(), str.rend()) + ' ';
        }
        
        return res == ""? "": res.substr(0, res.length() - 1);
    }
};