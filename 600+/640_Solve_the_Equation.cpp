/* 640. Solve the Equation
 * there is two sub equations, left & right, calculate the value & coefficient of x per equation
 * isAdded is for correctly adding coefficient of 'x', if isAdded == false and encountering an 'x'
 * the coefficient should be added as 1 or -1 (eg. 1+x, cof += 1). But another situation is '+0x'
 * where isAdded = true, and this time we should add cof to 0 instead of 1 or -1
 */


class Solution {
public:
    string solveEquation(string equation) {
        int lcof = 0, lval = 0, rcof = 0, rval = 0;
        int equmark = calXAndValue(lcof, lval, equation, 0);
        calXAndValue(rcof, rval, equation, equmark);
        
        if(lcof == rcof){
            if(lval == rval) return "Infinite solutions";
            else return "No solution";
        }else{
            int xval = (lval - rval)/(rcof - lcof);
            return "x=" + to_string(xval);
        }
    }
    
    int calXAndValue(int& cof, int& val, const string& equ, int start){
        bool positive = true;
        bool isAdded = false;
        int num = 0;
        for(int i = start; i < equ.size(); ++i){
            if(equ[i] == '='){
                val += positive? num:-1*num;
                return i+1;
            }else if(isdigit(equ[i])){
                isAdded = true;
                num *= 10;
                num += equ[i] - '0';
            }else if(equ[i] == '+'){
                val += positive? num: -1*num;
                num = 0;
                isAdded = false;
                positive = true;
            }else if(equ[i] == '-'){
                val += positive? num: -1*num;
                num = 0;
                isAdded = false;
                positive = false;
            }else if(equ[i] == 'x'){
                if(num == 0 && !isAdded){
                    cof += positive?1: -1;
                }else{
                    cof += positive? num: -1*num;
                }
                num = 0;
                positive = true;
            }
        }
        val += positive? num:-1*num;
        return equ.size();
    }
};