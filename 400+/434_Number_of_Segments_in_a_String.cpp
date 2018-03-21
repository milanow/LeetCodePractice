/* 434. Number of Segments in a String
 * Counting how many continuous two characters where previous character is ' ' and
 * next character is not ' '
 */

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, start = 0;
        while(start < s.length() && s[start] == ' ') start++;
        for(int i = start; i < s.length(); i++){
            if(i == 0 || s[i] != ' ' && s[i-1] == ' ') cnt++;
        }
        return cnt;
    }
};