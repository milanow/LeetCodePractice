/* 777. Swap Adjacent in LR String
 * After observation, the rule of this problem is actually:
 * 1.for each 'L's in 'start', it can only be moved backwards
 * 2.for each 'R's in 'start', it can only be moved forwards
 * 3.the subsequence of 'L's and 'R's cannot be changed after operations
 * So according to these 3 rules, the algorithm is mainly checking
 * if start and end string meets all 3 rules above
 */

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int i = 0, j = 0;
        while(i < n && j < n){
            while(i < n && start[i] == 'X') i++;
            while(j < n && end[j] == 'X') j++;
            if(i == n && j == n) break;
            // the subsequence of 'L' & 'R" in start and end is not equal
            if(i == n || j == n || start[i] != end[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            else if(start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        return true;
    }
};