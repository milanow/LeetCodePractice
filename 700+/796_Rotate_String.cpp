/* 796. Rotate String
 * If A and B are not equal length, then it cannot be shifted from A to B
 * Then in each iteration, dividing the string into two parts and reversely linking
 * two parts together, and checking if it is same with B
 */

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        if(A == B) return true;
        for(int i = 1; i < A.length(); i++){
            if(A.substr(i) + A.substr(0, i) == B) return true;
        }
        return false;
    }
};