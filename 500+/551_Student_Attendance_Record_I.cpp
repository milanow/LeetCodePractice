/* 551. Student Attendance Record I
 * keep recording 'L's and 'A' to see if any incoming character violates the rule
 */
 
class Solution {
public:
    bool checkRecord(string s) {
        int hasA = 0, cntL = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                if(hasA > 0) return false;
                hasA += 1;
                cntL = 0;
            }else if(s[i] == 'L'){
                if(cntL >= 2) return false;
                cntL++;
            }else{
                cntL = 0;
            }
        }
        return true;
    }
};