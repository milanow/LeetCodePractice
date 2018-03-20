/* 423. Reconstruct Original Digits from English
 * Find the unique character for each digits is easy for us to find out how many digits
 * in the string. Note that the unique character means unique in left numbers
 * e.g. five and four, after eliminating 'four' using 'u', 'f' can be unique in the rest
 * of English numbers
 */

class Solution {
public:
    string originalDigits(string s) {
        vector<char> nums = {'0', '8', '6', '4', '5', '7', '2', '3', '9', '1'};
        vector<char> distinct_char = {'z', 'g', 'x', 'u', 'f', 'v', 'w', 't', 'i', 'n'};
        vector<string> numstr = {"zero", "eight", "six", "four", "five", "seven", "two", "three", "nine", "one"};
        vector<int> count(26, 0);
        for(char c: s) count[c - 'a']++;
        string res;
        for(int i = 0; i < 10; i++){
            int cnt = count[distinct_char[i] - 'a'];
            res.append(cnt, nums[i]);
            
            for(int j = 0; j < numstr[i].length(); j++){
                count[numstr[i][j] - 'a'] -= cnt;
            }
        }
        sort(res.begin(), res.end());
        return res;
        
    }
    
};