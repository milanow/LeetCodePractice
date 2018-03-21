/* 425. Word Squares
 * The key idea is to iteratively build up the square as required.
 * First we check any word in words has prefix "" (means all words)
 * Say we choose "wall", then the square becomes
 * w a l l
 * a
 * l
 * l
 * Then we check second line which word in words has prefix "a"
 * w a l l 
 * a r e a
 * l e
 * l a
 * Then we check third line which word in words has prefix "le"
 * And so on.
 * Putting all valid square (if exist) into final results
 */

class Solution {
    vector<string> square;
    vector<vector<string>> squares;
    int n;
    unordered_map<string, vector<string>> mp;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].size();
        square.resize(n);
        for(string word: words){
            for(int i = 0; i < n; i++){
                mp[word.substr(0, i)].push_back(word);
            }
        }
        build(0);
        return squares;
    }
    
private:
    void build(int i){
        if(i == n){
            squares.push_back(square);
            return;
        }
        
        string prefix;
        for(int k = 0; k < i; k++){
            prefix += square[k][i];
        }
        for(string word: mp[prefix]){
            square[i] = word;
            build(i + 1);
        }
    }
};